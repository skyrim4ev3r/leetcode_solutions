class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        res = 0

        for i in range(1, n):
            if nums[i] == nums[i - 1]:
                res ^= nums[i]

        return res
