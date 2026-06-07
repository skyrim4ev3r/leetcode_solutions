WATER: chr = '0'
LAND: chr = '1'
LAND_VISITED: chr = '2'

class Solution:
    def dfs(self, grid, rows, cols, i, j):
        if i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] != LAND:
            return

        grid[i][j] = LAND_VISITED

        self.dfs(grid, rows, cols, i + 1, j)
        self.dfs(grid, rows, cols, i - 1, j)
        self.dfs(grid, rows, cols, i, j + 1)
        self.dfs(grid, rows, cols, i, j - 1)

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    count += 1
                    self.dfs(grid, rows, cols, i, j)

        return count
