INT_MAX = sys.maxsize

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        curr_min_price = INT_MAX
        max_profit = 0

        for price in prices:
            if curr_min_price < price:
                max_profit = max(max_profit, price - curr_min_price)
            else:
                curr_min_price = price

        return max_profit
