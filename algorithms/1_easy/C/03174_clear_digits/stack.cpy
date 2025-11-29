class Solution:
    def clearDigits(self, s: str) -> str:
        stack = []

        for ch in s:
            if (
                stack and
                ch in '0123456789' and
                stack[-1] not in '0123456789'
            ):
                stack.pop()
            else:
                stack.append(ch)

        return "".join(stack)
