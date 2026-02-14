"""
    Each glass with index j has 2 parent glasses: j and j - 1.

    Each glass receives half of the amount that its parents throw.

    using 2 arrays:
        -One array tracks the fill percentage of the glasses.
        -Another array tracks how much they throw.

    Fill the first glass parent with 2 * poured, so the first glass gets half of it.
        throw_info[0] = 2.0 * poured
"""

class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [0.0] * (query_row + 2)
        dp[0] = float(poured)

        for i in range(query_row):
            for j in range(i, -1, -1):
                amount = max(0.0, (dp[j] - 1.0) / 2.0)
                dp[j] =  amount
                dp[j + 1] += amount

        return min(1.0, dp[query_glass])
