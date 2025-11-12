class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:

        max_adjacent_inc_len = 0
        max_single_inc_len = 0
        nums_len = len(nums)
        prev_inc_len = 0
        curr_inc_len = 1

        for i in range(1, nums_len):
            if nums[i] > nums[i - 1]:
                curr_inc_len += 1
            else:
                max_adjacent_inc_len = max(max_adjacent_inc_len, min(curr_inc_len, prev_inc_len))
                max_single_inc_len = max(max_single_inc_len, curr_inc_len)
                prev_inc_len = curr_inc_len
                curr_inc_len = 1

        max_adjacent_inc_len = max(max_adjacent_inc_len, min(curr_inc_len, prev_inc_len))
        max_single_inc_len = max(max_single_inc_len, curr_inc_len)

        return max(max_adjacent_inc_len, max_single_inc_len // 2)
