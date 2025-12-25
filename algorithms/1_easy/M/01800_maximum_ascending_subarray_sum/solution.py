class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        curr_sum = nums[0]
        max_sum = nums[0]
        n = len(nums)

        for i in range(1, n):
            if nums[i - 1] < nums[i]:
                curr_sum += nums[i]
            else:
                curr_sum = nums[i]

            max_sum = max(max_sum, curr_sum)

        return max_sum
