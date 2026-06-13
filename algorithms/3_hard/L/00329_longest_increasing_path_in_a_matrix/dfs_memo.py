DIRECTIONS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

class Solution:
    def dfs(
        self,
        matrix: List[List[int]],
        dp: List[List[int]],
        i: int,
        j: int,
        rows: int,
        cols: int,
    ) -> int:
        if dp[i * cols + j] != -1:
            return dp[i * cols + j]

        cell_val = matrix[i][j]
        curr = 1

        for (dx, dy) in DIRECTIONS:
            ni = i + dx
            nj = j + dy

            if ni < 0 or nj < 0 or ni >= rows or nj >= cols or matrix[ni][nj] >= cell_val:
                continue

            curr = max(curr, 1 + self.dfs(matrix, dp, ni, nj, rows, cols))

        dp[i * cols + j] = curr
        return curr

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        dp = [-1] * (cols * rows)
        res = 0

        for i in range(rows):
            for j in range(cols):
                res = max(res, self.dfs(matrix, dp, i, j, rows, cols))

        return res
