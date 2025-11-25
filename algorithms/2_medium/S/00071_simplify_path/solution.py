class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = path.split('/')
        stack = []

        for part in parts:
            match part:
                case "" | ".":
                    continue
                case "..": 
                    if stack:
                        stack.pop()
                case _:
                    stack.append(part)

        res = "/"
        n = len(stack)

        for (i, s) in enumerate(stack):
            res += s
            if i != n - 1:
                res += "/"

        return res
