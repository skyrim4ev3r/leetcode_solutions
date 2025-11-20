class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        if n == 2:
            return max(nums[0], nums[1])

        nums[2] += nums[0]

        for i in range(3, n):
            nums[i] += max(nums[i - 2], nums[i - 3])

        return max(nums[n - 1], nums[n - 2])
