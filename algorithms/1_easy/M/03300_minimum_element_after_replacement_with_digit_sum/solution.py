class Solution:
    def minElement(self, nums: List[int]) -> int:
        min_sum = sys.maxsize

        for num in nums:
            dig_sum = 0

            while num > 0:
                dig_sum += num % 10
                num //= 10

            min_sum = min(min_sum, dig_sum);

        return min_sum
