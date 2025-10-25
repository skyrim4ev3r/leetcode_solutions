class Solution:
    def isValid(self, s: str) -> bool:

        stack = []

        for ch in s:
            match ch:
                case '}' | ']' | ')':
                    if stack:
                        top_char = stack.pop()

                        if (ch == '}' and top_char != '{') or \
                           (ch == ']' and top_char != '[') or \
                           (ch == ')' and top_char != '('):
                            return False
                    else:
                        return False

                case _:
                    stack.append(ch)

        return len(stack) == 0
