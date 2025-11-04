class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:

        stack = []
        temperatures_len = len(temperatures)
        res = [0] * temperatures_len

        for i in range(temperatures_len - 1, -1, -1):
            while stack and stack[-1][0] <= temperatures[i]:
                stack.pop()

            if stack:
                old_index = stack[-1][1]
                res[i] = old_index - i

            stack.append([temperatures[i], i])

        return res
