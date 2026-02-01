DIRECTIONS = [(0, 1), (1, 0), (-1, 0), (0, -1)]

class Solution:
    def dfs(
        self,
        grid: List[List[int]],
        rows: int,
        cols: int,
        i: int,
        j: int,
    ):
        if i >= rows or j >= cols or i < 0 or j < 0 or grid[i][j] == 0:
            return

        grid[i][j] = 0

        for (dx, dy) in DIRECTIONS:
            self.dfs(grid, rows, cols, i + dx, j + dy)

    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            if grid[i][0] == 1:
                self.dfs(grid, rows, cols, i, 0)

            if grid[i][cols - 1] == 1:
                self.dfs(grid, rows, cols, i, cols - 1)

        for j in range(cols):
            if grid[0][j] == 1:
                self.dfs(grid, rows, cols, 0, j)

            if grid[rows - 1][j] == 1:
                self.dfs(grid, rows, cols, rows - 1, j)

        count = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    count += 1

        return count
