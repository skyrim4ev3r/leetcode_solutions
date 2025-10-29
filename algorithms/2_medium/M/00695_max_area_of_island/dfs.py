directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

class Solution:
    def dfs(self, grid, i, j):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 0:
            return

        self.count += 1
        grid[i][j] = 0

        for (dx, dy) in directions:
            self.dfs(grid, i + dx, j + dy)

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    self.count = 0
                    self.dfs(grid, i, j)
                    max_area = max(max_area, self.count)

        return max_area
