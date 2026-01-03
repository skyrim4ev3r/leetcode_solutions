PRE_CALC_PRIMES = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97
]

class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        def is_prime(num):
            if num in PRE_CALC_PRIMES:
                return True

            return False
        n  = len(nums)
        left = 0
        right = n - 1

        while left < n and not is_prime(nums[left]):
            left += 1

        while right < n and not is_prime(nums[right]):
            right -= 1

        return right - left
