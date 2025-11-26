MOD_TO = 1_000_000_007

class Solution:
    def dfs(self, grid, dp, m, n, k, i, j, curr_mod):
        if i >= m or j >= n:
            return 0

        new_mod = (curr_mod + grid[i][j]) % k

        if i == m - 1 and j == n - 1:
            return 1 if new_mod == 0 else 0

        if dp[i][j][new_mod ] != - 1:
            return dp[i][j][new_mod]

        res = (self.dfs(grid, dp, m, n, k, i + 1, j, new_mod) + \
               self.dfs(grid, dp, m, n, k, i, j + 1, new_mod)) % MOD_TO

        dp[i][j][new_mod] = res
        return res

    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[[-1] * k for _ in range(n)] for _ in range(m)]

        return self.dfs(grid, dp, m, n, k, 0, 0, 0)
