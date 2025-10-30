class Solution:
    def my_pow_helper(self, x, n):
        if n == 1:
            return x

        res_pow = self.my_pow_helper(x, n // 2)

        res_pow *= res_pow

        if (n & 1) == 1:
            res_pow *= x

        return res_pow

    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0

        if n < 0:
            return 1 / self.my_pow_helper(x, abs(n))

        return self.my_pow_helper(x, n)
