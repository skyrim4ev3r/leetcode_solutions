from bisect import bisect_left
import sys

INT_MAX = sys.maxsize

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        potions_len = len(potions)
        res = []

        for spell in spells:
            min_success_num = (success + spell - 1) // spell

            if min_success_num > INT_MAX:
                res.append(0)
            else:
                index = bisect_left(potions, min_success_num)
                res.append(potions_len - index)

        return res
