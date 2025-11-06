class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = [-1] * len(nums)
        for i in range(len(nums)):
            for ans in range((nums[i] // 2), nums[i]):
                if (ans | (ans + 1)) == nums[i]:
                    res[i] = ans
                    break

        return res
