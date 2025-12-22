DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
class Solution:
    def dfs(
        self,
        grid: List[List[int]],
        is_visited: List[List[bool]],
        rows: int,
        cols: int,
        i: int,
        j: int,
    ):
        if i >= rows or i < 0 or j >= cols or j < 0 or grid[i][j] == 1 or is_visited[i][j]:
            return

        is_visited[i][j] = True

        for (dx, dy) in DIRECTIONS:
            self.dfs(grid, is_visited, rows, cols, i + dx, j + dy)

    def closedIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        is_visited = [[False] * cols for _ in range(rows)]
        count = 0

        for i in range(rows):
            if grid[i][0] == 0 and is_visited[i][0] == False:
                self.dfs(grid, is_visited, rows, cols, i, 0)

            if grid[i][cols - 1] == 0 and is_visited[i][cols - 1] == False:
                self.dfs(grid, is_visited, rows, cols, i, cols - 1)

        for j in range(cols):
            if grid[0][j] == 0 and is_visited[0][j] == False:
                self.dfs(grid, is_visited, rows, cols, 0, j)

            if grid[rows - 1][j] == 0 and is_visited[rows - 1][j] == False:
                self.dfs(grid, is_visited, rows, cols, rows - 1, j)

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0 and is_visited[i][j] == False:
                    count += 1
                    self.dfs(grid, is_visited, rows, cols, i, j)

        return count
