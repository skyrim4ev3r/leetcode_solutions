class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)

        curr_sum = 0
        for i in range(len(nums)):
            res[i] += curr_sum
            curr_sum += nums[i]

        curr_sum = 0
        for i in range(len(nums) - 1, -1, -1):
            res[i] = abs(res[i] - curr_sum)
            curr_sum += nums[i]

        return res
