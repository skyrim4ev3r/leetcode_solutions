class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n = len(piles)
        assert(n % 3 == 0)
        piles.sort()

        j = n - 2
        i = 0
        amount = 0

        while i < j:
            amount += piles[j]
            j -= 2
            i += 1

        return amount
