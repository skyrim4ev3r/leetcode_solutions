class Solution:
    def pivotIndex(self, nums: List[int]) -> int:

        nums_len = len(nums); 
        postfix_sum = sum(nums)
        prefix_sum = 0

        for i in range(nums_len):
            if i > 0:
                prefix_sum += nums[i - 1]

            postfix_sum -= nums[i]

            if prefix_sum == postfix_sum:
                return i

        return -1
