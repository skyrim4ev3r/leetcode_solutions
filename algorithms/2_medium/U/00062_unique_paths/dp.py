class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        rows = max(m, n)
        cols = min(m, n)
        dp = [1] * cols
        dp_next = [0] * cols

        for _ in range(1, rows):
            dp_next[0] = 1
            for j in range(1, cols):
                dp_next[j] = dp_next[j - 1] + dp[j]
            temp = dp
            dp = dp_next
            dp_next = temp

        return dp[cols - 1]
