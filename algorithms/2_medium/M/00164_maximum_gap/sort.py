class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()

        max_gap = 0
        nums_len = len(nums)

        for i in range(1, nums_len):
            max_gap = max(max_gap, nums[i] - nums[i - 1])

        return max_gap
