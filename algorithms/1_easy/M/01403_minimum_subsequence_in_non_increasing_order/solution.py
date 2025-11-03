class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()

        sum_left = sum(nums)
        sum_right = 0
        index = len(nums) - 1
        res = []

        while sum_left >= sum_right:
            sum_right += nums[index]
            sum_left -= nums[index]
            res.append(nums[index])
            index -= 1

        return res
