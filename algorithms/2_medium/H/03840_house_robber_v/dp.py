from dataclasses import dataclass

@dataclass
class AmountColor:
    amount: int
    color: int

class Solution:
    def rob(self, nums: List[int], colors: List[int]) -> int:
        n = len(nums)
        prev = AmountColor(0, 0)
        prev_prev = AmountColor(0, 0)

        for i in range(n):
            amount_to_add = 0
            if colors[i] == prev.color:
                amount_to_add = prev_prev.amount
            else:
                amount_to_add = max(prev_prev.amount, prev.amount)

            curr = AmountColor(nums[i] + amount_to_add, colors[i])
            (prev_prev, prev) = (prev if prev_prev.amount < prev.amount else prev_prev, curr)

        return max(prev.amount, prev_prev.amount)
