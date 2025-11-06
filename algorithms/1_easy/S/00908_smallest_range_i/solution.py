INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize - 1

class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        min_num = INT_MAX
        max_num = INT_MIN

        for num in nums:
            if num > max_num:
                max_num = num
            if num < min_num:
                min_num = num

        return max(0, (max_num - min_num) - 2 * k)

