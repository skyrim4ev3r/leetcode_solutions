class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        min_sum = sys.maxsize
        curr_sum = 0

        for num in nums:
            curr_sum += num
            min_sum = min(min_sum, curr_sum)

        return max(1, min_sum * -1 + 1)
