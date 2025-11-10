class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        r = len(nums)
        while r != 1:
            for i in range(r - 1):
                nums[i] += nums[i + 1]
                if nums[i] >= 10:
                    nums[i] -= 10
            r -= 1

        return nums[0]
