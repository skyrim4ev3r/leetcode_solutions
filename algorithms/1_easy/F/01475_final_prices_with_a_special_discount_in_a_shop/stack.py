class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack = []
        n = len(prices)
        res = [0] * n

        for i in range(n - 1, -1, -1):
            while stack and stack[-1] > prices[i]:
                stack.pop()
            if stack:
                res[i] = prices[i] - stack[-1]
            else:
                res[i] = prices[i]

            stack.append(prices[i])

        return res
