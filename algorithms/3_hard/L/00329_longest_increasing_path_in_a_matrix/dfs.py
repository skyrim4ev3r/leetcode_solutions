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
        cache = dp[i][j]
        if cache != -1:
            return cache

        longest = 1
        curr_cell = matrix[i][j]

        for (dx, dy) in DIRECTIONS:
            new_i = i + dx
            new_j = j + dy

            if new_i < 0 or new_j < 0 or new_i >= rows or new_j >= cols or matrix[new_i][new_j] >= curr_cell:
                continue

            longest = max(longest, 1 + self.dfs(matrix, dp, new_i, new_j, rows, cols))

        dp[i][j] = longest
        return longest

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        dp = [[-1] * cols for _ in range(rows)]
        res = 0

        for i in range(rows):
            for j in range(cols):
                res = max(res, self.dfs(matrix, dp, i, j, rows, cols))

        return res
