class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        res = [0] * len(heights)
        stack = []

        for i in range(len(heights) - 1, -1, -1):
            while stack:
                res[i] += 1
                val = stack[-1]

                if val <= heights[i]:
                    stack.pop()
                else:
                    break

            stack.append(heights[i])

        return res
