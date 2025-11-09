class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        if k == 1:
            return 0 # No range to consider

        nums.sort()
        left = 0
        right = k - 1
        min_difference = 1e10    # Initialize to big value
        while right < len(nums):
            min_difference = min(min_difference, nums[right] - nums[left])
            right += 1
            left += 1

        return min_difference
