class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        even_count = 0
        for num in nums:
            if (num & 1) == 0:
                even_count += 1

        for i in range(len(nums)):
            if i < even_count:
                nums[i] = 0
            else:
                nums[i] = 1

        return nums
