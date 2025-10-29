class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums_len = len(nums)

        nums.sort()

        return max(nums[0] * nums[1] * nums[nums_len - 1], nums[nums_len - 1] * nums[nums_len - 2] * nums[nums_len - 3])
