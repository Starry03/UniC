import regex as re

DOC_PATTERN: str = r"(\/\*\*[^\/]*\*\/)"
FUNCTION_HEADER_PATTERN: str = r"(\w+\s+\w+\((\s*\w+\s+\S+[,]*)+\))"
BRACKET_PATTERN: str = r"(\{([^{}]|(?R))*\})"
FUNCTION_PATTERN: str = (
    DOC_PATTERN + r"{0,1}\s*" + FUNCTION_HEADER_PATTERN + r"{0,1}\s*" + BRACKET_PATTERN + r"{0,1}"
)


def test(pattern: str, log: bool) -> list:
    test_file: str = r"../DataStructures/Heap/Heap.c"
    with open(test_file, "r") as file:
        print(f"Testing pattern: {pattern}")
        p = re.compile(pattern, re.MULTILINE | re.DOTALL)
        m = p.findall(file.read())
        print(f"{len(m)} matches")
        if log:
            for el in list(m):
                print(len(el))
        return list(m)


doc = test(DOC_PATTERN, False)
test(FUNCTION_HEADER_PATTERN, True)
test(BRACKET_PATTERN, False)
res = test(FUNCTION_PATTERN, False)
