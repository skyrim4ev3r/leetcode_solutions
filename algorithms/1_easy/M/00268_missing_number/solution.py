class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)

        for i in range(n):
            num_as_index = abs(nums[i]) - 1 if nums[i] < 0 else nums[i]

            if num_as_index != n:
                nums[num_as_index] = -1 * nums[num_as_index] - 1

        for index, num in enumerate(nums):
            if num >= 0:
                return index

        return n
