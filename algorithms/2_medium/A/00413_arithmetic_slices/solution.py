class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        prev_diff = 0
        curr_len = 0
        count = 0

        for i in range(1, n):
            if nums[i] - nums[i - 1] == prev_diff:
                curr_len += 1
            else:
                curr_len = 1

            count += curr_len - 1
            prev_diff = nums[i] - nums[i - 1]

        return count
