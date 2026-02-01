class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        arr = list(s)
        stack = []

        for (i, ch) in enumerate(arr):
            if  ch == '(':
                stack.append((ch, i))
            elif ch == ')':
                if stack and stack[-1][0] == '(':
                    stack.pop()
                else:
                    stack.append((ch, i))

        for (_, index) in stack:
            arr[index] = '*'

        filtered_list = [ch for ch in arr if ch != '*']

        return "".join(filtered_list)
