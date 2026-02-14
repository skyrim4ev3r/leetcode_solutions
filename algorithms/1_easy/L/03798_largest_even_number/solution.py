class Solution:
    def largestEven(self, s: str) -> str:
        stack = list(s)

        while stack and stack[-1] == '1':
            stack.pop()

        return "".join(stack)
