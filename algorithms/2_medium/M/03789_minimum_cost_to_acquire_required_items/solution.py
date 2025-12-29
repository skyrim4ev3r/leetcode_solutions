class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        buy_base_together = min(need1, need2) * costBoth
        buy_extra_together = abs(need2 - need1) * costBoth
        buy_extra_seperate = cost2 * (need2 - need1) if need2 > need1 else cost1 * (need1 - need2)

        buy_together = buy_base_together + min(buy_extra_together, buy_extra_seperate)
        buy_seperate = (cost1 * need1) + (cost2 * need2)

        return min(buy_seperate, buy_together)
