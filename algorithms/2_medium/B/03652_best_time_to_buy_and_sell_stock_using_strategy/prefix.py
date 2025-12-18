class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + (prices[i] * strategy[i])

        curr = sum(prices[(k // 2) : k])
        max_sum = prefix[n]
        max_sum = max(max_sum, prefix[n] - prefix[k] + curr)

        for i in range(k, n):
            curr = curr - prices[i - (k // 2)] + prices[i]
            max_sum = max(max_sum, prefix[n] - prefix[i + 1] + prefix[i - k + 1] + curr)

        return max_sum
