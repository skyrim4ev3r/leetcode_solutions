class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        sqrt_len = int(sqrt(n))
        for i in range(1, sqrt_len + 1):
            if n % i == 0:
                other_index = n // i
                res += nums[i - 1] ** 2
                if other_index != i:
                    res += nums[other_index - 1] ** 2

        return res
