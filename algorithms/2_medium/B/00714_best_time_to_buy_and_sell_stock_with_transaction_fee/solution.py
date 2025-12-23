class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy = sys.maxsize
        profit = 0

        for price in prices:
            if price - fee > buy:
                profit += price - fee - buy
                buy = price - fee

            buy = min(buy, price)

        return profit
