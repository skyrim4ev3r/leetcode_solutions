class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        res = 0

        for i in range(1, n):
            if nums[i - 1] >= nums[i]:
                res += nums[i - 1] - nums[i]
        return res
