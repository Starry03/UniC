import regex as re
from dataclasses import dataclass, asdict
import os
import json
import psycopg2
from dotenv import load_dotenv
import logging

DOC_PATTERN: str = r"(\/\*\*[^\/]*\*\/)"
FUNCTION_HEADER_PATTERN: str = r"((?:\w+\s+)*\w+\s+(\w+)\((?:\s*\w+\s+\S+[,]*)+\))"
BRACKET_PATTERN: str = r"(\{(?:[^{}]|(?R))*\})"
PATTERN: str = (
    r"(?:"
    + DOC_PATTERN
    + r"*\s*"
    + FUNCTION_HEADER_PATTERN
    + r"\s*"
    + BRACKET_PATTERN
    + r")"
)
load_dotenv()
logging.basicConfig(level=logging.DEBUG)

db = psycopg2.connect(
    dbname=os.getenv("POSTGRES_DB"),
    user=os.getenv("POSTGRES_USER"),
    password=os.getenv("POSTGRES_PASSWORD"),
    host=os.getenv("POSTGRES_HOST"),
    port=os.getenv("POSTGRES_PORT"),
)

logging.info("Connected to database")

cursor = db.cursor()
cursor.execute(
    """
    CREATE SCHEMA IF NOT EXISTS functions;
"""
)

logging.info("Created schema")

cursor.execute(
    """
    CREATE TABLE IF NOT EXISTS functions.function (
        category VARCHAR(255),
        name VARCHAR(255),
        header VARCHAR(255) UNIQUE,
        body TEXT,
        doc TEXT
    );
	"""
)

logging.info("Created table")

@dataclass
class FunctionDoc:
    doc: str
    name: str
    header: str
    body: str


@dataclass
class FileDoc:
    name: str
    functions: tuple[FunctionDoc]

    @staticmethod
    def generate_from_file(file: str) -> "FileDoc":
        with open(file, "r") as f:
            content: str = f.read()
            res: list = get_match(
                PATTERN,
                content,
            )
            out: tuple[FunctionDoc] = tuple(
                [FunctionDoc(doc=m[0], name=m[2], header=m[1], body=m[3]) for m in res]
            )
        return FileDoc(name=file, functions=out)


@dataclass
class FolderWrapper:
    name: str
    subfolders: list["FolderWrapper"]
    files: list[FileDoc]

    def add_file_doc(self, file_doc: FileDoc) -> None:
        self.files.append(file_doc)

    def add_folder(self, folder: "FolderWrapper") -> None:
        self.subfolders.append(folder)

    def __eq__(self, other: "FolderWrapper") -> bool:
        return self.name == other.name

    def __gt__(self, other: "FolderWrapper") -> bool:
        return self.name > other.name

    def __lt__(self, other: "FolderWrapper") -> bool:
        return self.name < other.name


def get_match(pattern: str, content: str) -> list:
    p = re.compile(pattern, re.MULTILINE | re.DOTALL)
    m = p.findall(content)
    return list(m)


def build_dir_doc(
    path: str,
    extensions: list[str] = ["c"],
    path_exclusions: list[str] = [".", "examples", "doc", "build", "test"],
    file_exclusions: list[str] = ["main.c"],
) -> FolderWrapper:
    wrapper = FolderWrapper(name=path, subfolders=[], files=[])
    for file in os.listdir(path):
        if (
            any([file.startswith(s) for s in path_exclusions])
            or file in file_exclusions
        ):
            continue
        eval_path: str = os.path.join(path, file)
        if not os.path.isdir(eval_path):
            if file.split(".")[-1] in extensions:
                file_doc: FileDoc = FileDoc.generate_from_file(eval_path)
                category: str = (
                    file_doc.name.split("/")[-2]
                    if file_doc.name.count("/") > 1
                    else "General"
                )
                for function in file_doc.functions:
                    try:
                        cursor.execute(
                            """
                            INSERT INTO functions.function (category, name, header, body, doc)
                            VALUES (%s, %s, %s, %s, %s);
                            """,
                            (category, function.name, function.header, function.body, function.doc),
                        )
                    except (
                        psycopg2.errors.UniqueViolation,
                        psycopg2.errors.InFailedSqlTransaction,
                    ):
                        continue
                wrapper.add_file_doc(file_doc)
            continue
        wrapper.add_folder(build_dir_doc(eval_path))
    return wrapper


def test(path: str) -> None:
    """
    test

    Args:
        path (str): file path
    """
    d = FileDoc.generate_from_file(path)
    for f in d.functions:
        print("function:")
        print(f"{f.doc}")


wr = build_dir_doc("./")
# j = json.dumps(asdict(wr), indent=4)
# with open("doc/doc.json", "w") as f:
#     f.write(j)
db.commit()
cursor.close()
db.close()

logging.info("Disconnected from database")
