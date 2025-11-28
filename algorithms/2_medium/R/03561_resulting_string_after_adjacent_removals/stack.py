class Solution:
    def are_consecutive(self, a, b):
        return (
            a == b - 1 or
            a == b + 1 or
            (a == ord('z') and b == ord('a')) or
            (a == ord('a') and b == ord('z'))
        )

    def resultingString(self, s: str) -> str:
        stack = []

        for ch in s:
            if stack and self.are_consecutive(ord(stack[-1]), ord(ch)):
                stack.pop()
            else:
                stack.append(ch)

        return "".join(stack)
