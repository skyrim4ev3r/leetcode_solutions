class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD_TO = 1_000_000_007
        m = len(grid)
        n = len(grid[0])
        dp = [[[0, 0]for _ in range(n)] for _ in range(m)]
        dp[0][0] = [1, 1]

        for i in range(1, m):
            if grid[i - 1][0] == 1:
                break
            dp[i][0][1] = 1
        for j in range(1, n):
            if grid[0][j - 1] == 1:
                break
            dp[0][j][0] = 1

        for i in range(1, m):
            for j in range(1, n):
                if grid[i - 1][j] == 0:
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD_TO
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % MOD_TO
                else:
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD_TO

                if grid[i][j - 1] == 0:
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0]) % MOD_TO
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][1]) % MOD_TO
                else:
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][1]) % MOD_TO

        return (dp[m - 1][n - 1][0] +  dp[m - 1][n - 1][1]) % MOD_TO
