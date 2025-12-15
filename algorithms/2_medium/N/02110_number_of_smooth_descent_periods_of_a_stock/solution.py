class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        count = 0
        i = 0

        while i < n:
            continues = 1

            while i + 1 < n and prices[i] - 1 == prices[i + 1]:
                i += 1
                continues += 1

            count += continues * (continues + 1) // 2
            i += 1

        return count
