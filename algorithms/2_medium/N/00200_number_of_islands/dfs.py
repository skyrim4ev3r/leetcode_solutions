class Solution:
    def dfs(self, grid, directions, i, j):

        if grid[i][j] == '0':
            return

        grid[i][j] = '0'

        for (x, y) in directions:

            new_i = i + x
            new_j = j + y

            if new_i < 0 or new_j < 0 or new_i >= len(grid) or new_j >= len(grid[0]):
                continue

            self.dfs(grid, directions, new_i, new_j)

    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        count = 0
        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    count += 1
                    self.dfs(grid, directions, i, j)

        return count
