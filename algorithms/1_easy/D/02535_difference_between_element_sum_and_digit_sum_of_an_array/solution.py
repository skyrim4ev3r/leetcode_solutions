class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        nums_sum = 0
        digits_sum = 0

        for num in nums:
            nums_sum += num
            while num > 0:
                digits_sum += num % 10
                num //= 10

        return nums_sum - digits_sum # No need for abs(), nums_sum is always greater
