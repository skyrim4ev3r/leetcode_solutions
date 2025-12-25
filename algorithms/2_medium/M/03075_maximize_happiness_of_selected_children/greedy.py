class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(key=lambda x: -x)
        res = 0

        for (i, h) in enumerate(happiness):
            if h <= i or i == k:
                break

            res += h - i

        return res
