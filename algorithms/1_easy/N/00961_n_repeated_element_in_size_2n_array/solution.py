class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums)

        for i in range(n - 2):
            if nums[i] == nums[i + 1] or nums[i] == nums[i + 2]:
                return nums[i]

            if nums[i + 1] == nums[i + 2]:
                return nums[i + 1]

        if nums[0] == nums[n - 1]:
            return nums[0]

        return -1
