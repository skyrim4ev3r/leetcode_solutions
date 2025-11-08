class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
        total_sum = 0
        nums_len = len(nums)

        for i in range(nums_len):
            if (i & 1) == 0:
                total_sum += nums[i]
            else:
                total_sum -= nums[i]

        return total_sum
