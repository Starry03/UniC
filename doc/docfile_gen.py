import regex as re
from dataclasses import dataclass, asdict
import os
import json


@dataclass
class FunctionDoc:
    doc: str
    header: str
    body: str
    DOC_PATTERN: str = r"(\/\*\*[^\/]*\*\/)"
    FUNCTION_HEADER_PATTERN: str = r"(\w+\s+\w+\((?:\s*\w+\s+\S+[,]*)+\))"
    BRACKET_PATTERN: str = r"(\{(?:[^{}]|(?R))*\})"


@dataclass
class FileDoc:
    functions: tuple[FunctionDoc]

    @staticmethod
    def generate_from_file(file: str) -> "FileDoc":
        out: tuple[FunctionDoc] = tuple()
        with open(file, "r") as f:
            content: str = f.read()
            doc: list[str] = get_match(FunctionDoc.DOC_PATTERN, content)
            headers: list[str] = get_match(FunctionDoc.FUNCTION_HEADER_PATTERN, content)
            bodies: list[str] = get_match(FunctionDoc.BRACKET_PATTERN, content)
            # trash
            max_len: int = max(len(doc), len(headers), len(bodies))
            doc += [""] * (max_len - len(doc))
            headers += [""] * (max_len - len(headers))
            bodies += [""] * (max_len - len(bodies))
            out = [FunctionDoc(doc[i], headers[i], bodies[i]) for i in range(len(doc))]
        return FileDoc(functions=out)


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
    path_exclusions: list[str] = ["."],
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
                wrapper.add_file_doc(FileDoc.generate_from_file(eval_path))
            continue
        wrapper.add_folder(build_dir_doc(eval_path))
    return wrapper


wr = build_dir_doc("./")
j = json.dumps(asdict(wr), indent=4)
with open("doc/doc.json", "w") as f:
    f.write(j)
