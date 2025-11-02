class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        max_count = 1
        curr_count = 1
        nums_len = len(nums)

        for i in range(1, nums_len):
            if nums[i] > nums[i - 1]:
                curr_count += 1
                max_count = max(max_count, curr_count)
            else:
                curr_count = 1

        return max_count
