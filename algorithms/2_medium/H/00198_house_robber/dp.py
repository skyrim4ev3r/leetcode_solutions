class Solution:
    def rob(self, nums: List[int]) -> int:
        prev_prev, prev, curr = (0, 0, 0)

        for num in nums:
            next_val = num + max(prev, prev_prev)
            prev_prev, prev, curr = (prev, curr, next_val)

        return max(curr, prev)
