class Solution:
    def countSubarrays(self, nums: List[int]) -> int:

        nums_len = len(nums)
        count = 0

        for i in range(nums_len - 2):
            if (nums[i + 1] & 1) == 0 and (nums[i] + nums[i + 2]) == nums[i + 1] / 2:
                count += 1

        return count
