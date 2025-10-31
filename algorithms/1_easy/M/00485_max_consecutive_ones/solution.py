class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_consecutive_ones = 0
        curr_consecutive_ones = 0

        for num in nums:
            if num == 1:
                curr_consecutive_ones += 1
                max_consecutive_ones = max(max_consecutive_ones, curr_consecutive_ones)
            else:
                curr_consecutive_ones = 0

        return max_consecutive_ones
