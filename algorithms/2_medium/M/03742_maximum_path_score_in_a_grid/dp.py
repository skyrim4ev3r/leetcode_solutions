class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        rows: int = len(grid)
        cols: int = len(grid[0])

        dp = [[[-1] * (k + 1) for _ in range(cols)] for _ in range(rows)]
        dp[0][0][0] = 0

        for i in range(rows):
            for j in range(cols):
                score_cell: int = grid[i][j]
                cost_cell: int = 1 if score_cell != 0 else 0

                if i > 0:
                    for c in range(k + 1):
                        if dp[i - 1][j][c] != -1:
                            if c + cost_cell <= k:
                                dp[i][j][c + cost_cell] = max(dp[i][j][c + cost_cell], dp[i - 1][j][c] + score_cell)

                if j > 0:
                    for c in range(k + 1):
                        if dp[i][j - 1][c] != -1:
                            if c + cost_cell <= k:
                                dp[i][j][c + cost_cell] = max(dp[i][j][c + cost_cell], dp[i][j - 1][c] + score_cell)

        return max(dp[rows - 1][cols - 1])
