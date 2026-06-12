class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for c in coins:
            for a in range(c, amount + 1):
                dp[a] = min(dp[a], dp[a - c] + 1)

        return -1 if dp[amount] > amount else dp[amount]
