class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)

        max_rows = []
        max_cols = []

        for i in range(n):
            curr_max = 0

            for j in range(n):
                curr_max = max(curr_max, grid[i][j])

            max_rows.append(curr_max)

        for j in range(n):
            curr_max = 0

            for i in range(n):
                curr_max = max(curr_max, grid[i][j])

            max_cols.append(curr_max)

        count = 0

        for i in range(n):
            for j in range(n):
                count += min(max_cols[j], max_rows[i]) - grid[i][j]

        return count
