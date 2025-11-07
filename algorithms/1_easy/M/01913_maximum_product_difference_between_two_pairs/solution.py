INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize - 1

class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:

        min1 = INT_MAX
        min2 = INT_MAX
        max1 = INT_MIN
        max2 = INT_MIN

        for num in nums:
            if num < min2:
                min1 = min2
                min2 = num
            elif num < min1:
                min1 = num

            if max2 < num:
                max1 = max2
                max2 = num
            elif max1 < num:
                max1 = num

        return (max1 * max2) - (min1 * min2)
