class Solution:
    def rob_helper(self, nums: List[int], start: int, end: int) -> int:
        prev_prev, prev, curr = 0, 0, 0

        for i in range(start, end):
            next_val = nums[i] + max(prev, prev_prev)
            (prev_prev, prev, curr) = (prev, curr, next_val)

        return max(prev, curr)

    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]

        max_dp1 = self.rob_helper(nums, 0, n - 1)
        max_dp2 = self.rob_helper(nums, 1, n)

        return max(max_dp1, max_dp2)
