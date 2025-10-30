INT_MIN = -sys.maxsize - 1

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        total_sum = 0
        total_max = INT_MIN

        for num in nums:
            total_sum += num
            total_max = max(total_max, total_sum)
            total_sum = max(total_sum, 0)

        return total_max
