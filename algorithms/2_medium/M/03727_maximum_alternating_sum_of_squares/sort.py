class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        num_len = len(nums)

        for i in range(num_len):
            nums[i] *= nums[i]

        nums.sort()
        plus_index = num_len//2
        t_sum = 0

        for i in range(plus_index):
            t_sum -= nums[i]

        for i in range(plus_index, num_len):
            t_sum += nums[i]

        return t_sum
