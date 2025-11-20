class Solution:
    def maximizeExpressionOfThree(self, nums: List[int]) -> int:
        max1 = -sys.maxsize - 1
        max2 = -sys.maxsize - 1
        min1 = sys.maxsize

        for num in nums:
            if num > max1:
                max2 = max1
                max1 = num
            else:
                max2 = max(max2, num)

            min1 = min(min1, num)

        return max1 + max2 - min1
