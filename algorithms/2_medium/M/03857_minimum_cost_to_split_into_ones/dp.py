class Solution:
    def minCost(self, n: int) -> int:
        assert(n > 0)
        if n == 1: return 0
        if n == 2: return 1

        dp = [0] * (n + 1)
        dp[1] = 0
        dp[2] = 1

        for i in range(3, n + 1):
            half = i // 2
            other = i - half
            dp[i] = (half * other) + dp[half] + dp[other]

        return dp[n]
