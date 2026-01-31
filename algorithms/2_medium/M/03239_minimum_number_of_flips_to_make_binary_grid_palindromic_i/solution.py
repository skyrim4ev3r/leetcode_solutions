class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        row_cost = 0
        col_cost = 0

        for i in range(rows // 2):
            other_i = rows - 1 - i

            for j in range(cols):
                if grid[i][j] != grid[other_i][j]:
                    row_cost += 1

        for j in range(cols // 2):
            other_j = cols - 1 - j

            for i in range(rows):
                if grid[i][j] != grid[i][other_j]:
                    col_cost += 1

        return min(col_cost, row_cost)
