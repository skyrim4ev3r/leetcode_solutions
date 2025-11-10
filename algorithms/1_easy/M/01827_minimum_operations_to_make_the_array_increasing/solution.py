class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = 0
        curr_max = nums[0]

        for i in range(1, len(nums)):
            if nums[i] <= curr_max:
                curr_max += 1
                count += curr_max - nums[i]
            else:
                curr_max = nums[i]

        return count
