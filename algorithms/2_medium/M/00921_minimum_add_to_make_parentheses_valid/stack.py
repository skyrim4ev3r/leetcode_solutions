class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []

        for ch in s:
            match ch:
                case ')':
                    if stack and stack[-1] == '(':
                        stack.pop()
                    else:
                        stack.append(ch)
                case _:
                    stack.append(ch)

        return len(stack)
