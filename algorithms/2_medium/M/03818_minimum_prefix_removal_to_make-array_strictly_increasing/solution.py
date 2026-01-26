class Solution:
    def minimumPrefixLength(self, nums: List[int]) -> int:
        n = len(nums)

        if n <= 1:
            return 0

        index = n - 1

        while index > 0 and nums[index] > nums[index - 1]:
            index -= 1

        return index
