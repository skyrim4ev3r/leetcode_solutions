class Solution:
    def sumAndMultiply(self, n: int) -> int:
        total_sum = 0
        p = 1
        res = 0

        while n // p >= 10:
            p *= 10

        while p > 0:
            dig = (n // p) % 10
            p //= 10

            if dig > 0:
                res *= 10
                res += dig
                total_sum += dig

        return res * total_sum
