class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        len_nums = len(nums)

        for i in range(1, len_nums):
            if nums[i - 1] == nums[i]:
                return True

        return False
