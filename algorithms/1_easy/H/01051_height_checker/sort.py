class Solution:
    def heightChecker(self, heights: List[int]) -> int:

        count = 0
        heights_len = len(heights)

        heights_sorted = heights.copy()
        heights_sorted.sort()

        for i in range(heights_len):
            if heights[i] != heights_sorted[i]:
                count += 1

        return count
