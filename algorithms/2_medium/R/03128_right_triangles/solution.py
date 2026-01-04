class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        prefix_cols = [0] * cols
        prefix_rows = [0] * rows
        count = 0

        for i in range(rows):
            for j in range(cols):
                prefix_cols[j] += grid[i][j]
                prefix_rows[i] += grid[i][j]

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    count += (prefix_rows[i] - 1) * (prefix_cols[j] - 1)

        return count
