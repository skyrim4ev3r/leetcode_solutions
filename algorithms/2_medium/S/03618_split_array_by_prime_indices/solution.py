class Solution:
    def is_prime(self, n):
        if n < 2:
            return False

        if n == 2 or n == 3 or n == 5:
            return True

        if n % 2 == 0 or n % 3 == 0 or n % 5 == 0:
            return False

        for i in range(7, int(sqrt(n)) + 1, 2):
            if n % i == 0:
                return False

        return True

    def splitArray(self, nums: List[int]) -> int:
        sum = 0
        for i in range(len(nums)):
            if self.is_prime(i):
                sum += nums[i]
            else:
                sum -= nums[i]

        return abs(sum)
