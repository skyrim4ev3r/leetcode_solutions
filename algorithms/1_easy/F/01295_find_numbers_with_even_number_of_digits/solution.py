class Solution:
    def findNumbers(self, nums: List[int]) -> int:

        count = 0

        for num in nums:

            digit_count = 0

            while num > 0:
                digit_count += 1
                num //= 10

            if (digit_count & 1) != 1:
                count += 1

        return count
