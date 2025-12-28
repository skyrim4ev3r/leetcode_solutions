class Solution:
    def makeGood(self, s: str) -> str:
        stack = []

        for ch in s:
            if stack and (
                ord(stack[-1]) + 32 == ord(ch) or
                ord(ch) + 32 == ord(stack[-1])
            ):
                stack.pop()
            else:
                stack.append(ch)

        return "".join(stack)
