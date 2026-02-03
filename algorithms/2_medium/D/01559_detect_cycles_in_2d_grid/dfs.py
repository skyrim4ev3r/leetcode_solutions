DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

class Solution:
    def dfs(
        self,
        grid: List[List[str]],
        visited: List[List[bool]],
        parent_char: str,
        i: int,
        j: int,
        rows: int,
        cols: int,
    ) -> bool:
        if self.has_cycle or i < 0 or j < 0 or i >= rows or j >= cols or grid[i][j] != parent_char:
            return False

        if visited[i][j]:
            return True

        visited[i][j] = True
        count = 0

        for (dx, dy) in DIRECTIONS:
            if self.dfs(grid, visited, parent_char, i + dx, j + dy, rows, cols):
                count += 1

            if count >= 2:
                self.has_cycle = True
                return False

        return False

    def containsCycle(self, grid: List[List[str]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])
        visited = [[0] * cols for _ in range(rows)]
        self.has_cycle = False

        for i in range(rows):
            for j in range(cols):
                if not visited[i][j]:
                    parent_char = grid[i][j]

                    self.dfs(grid, visited, parent_char, i, j, rows, cols)

                    if self.has_cycle:
                        return True

        return False
