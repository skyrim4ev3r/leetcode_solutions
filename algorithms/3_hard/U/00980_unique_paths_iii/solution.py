class Solution:
    def dfs(self, grid, curr_path_len, i, j):
        if i < 0 or j < 0 or i >= self.rows or j >= self.cols or grid[i][j] == -1:
            return

        if grid[i][j] == 2:
            if self.target_path_len == curr_path_len:
                self.count += 1
            return

        grid[i][j] = -1
        for direction in self.directions:
            new_i = i + direction[0]
            new_j = j + direction[1]

            self.dfs(grid, curr_path_len + 1, new_i, new_j)

        grid[i][j] = 0

    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.count = 0
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        self.target_path_len = 0
        i_start = 0
        j_start = 0

        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == 0 or grid[i][j] == 2:
                    self.target_path_len += 1

                if grid[i][j] == 1:
                    i_start = i
                    j_start = j

        self.dfs(grid, 0, i_start, j_start)

        return self.count
