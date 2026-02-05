class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        curr = 0

        for coin in coins:
            if coin <= curr+ 1:
                curr += coin
            else:
                break

        return curr + 1 # len([0..curr]) is curr + 1
