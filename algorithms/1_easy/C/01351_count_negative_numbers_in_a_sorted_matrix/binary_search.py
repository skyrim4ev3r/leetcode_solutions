class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0

        for row in grid:
            count += bisect.bisect_right(row[-1::-1], -1)

        return count
