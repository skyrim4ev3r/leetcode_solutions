DIRECTIONS = [(1, 0), (-1, 0), (0, 1), (0, -1)]

class Solution:
    def dfs(self, grid, rows, cols, i, j):
        if i >= rows or i < 0 or j >= cols or j < 0 or grid[i][j] == 0:
            return 0

        total_sum = grid[i][j]
        grid[i][j] = 0

        for dx, dy in DIRECTIONS:
            total_sum += self.dfs(grid, rows, cols, i + dx, j + dy)

        return total_sum

    def findMaxFish(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        max_sum = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] > 0:
                    max_sum = max(max_sum, self.dfs(grid, rows, cols, i, j))

        return max_sum
