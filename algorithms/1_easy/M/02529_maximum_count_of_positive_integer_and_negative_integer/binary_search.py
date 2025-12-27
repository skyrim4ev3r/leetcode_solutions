class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        lower_bound_zero = bisect.bisect_left(nums, 0)
        upper_bound_zero = bisect.bisect_right(nums, 0)
        n = len(nums)

        return max(n - upper_bound_zero, lower_bound_zero)
