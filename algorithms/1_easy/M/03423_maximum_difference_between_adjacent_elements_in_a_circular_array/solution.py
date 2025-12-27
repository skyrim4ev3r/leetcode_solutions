class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        max_diff = abs(nums[n - 1] - nums[0])

        for i in range(n - 1):
            max_diff = max(max_diff, abs(nums[i + 1] - nums[i]))

        return max_diff
