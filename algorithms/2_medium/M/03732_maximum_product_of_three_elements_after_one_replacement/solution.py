class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1 = 0
        max2 = 0

        for num in nums:
            abs_num = abs(num)

            if abs_num > max1:
                max2 = max1
                max1 = abs_num
            elif abs_num > max2:
                max2 = abs_num

        return max1 * max2 * 100_000
