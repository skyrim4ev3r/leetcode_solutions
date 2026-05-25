class Solution:
    def pow_recursion(self, x, n):
        if n == 0:
            return 1

        res = self.pow_recursion(x, n // 2)

        if (n & 1) == 1:
            return res * res * x

        return res * res

    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1 / self.pow_recursion(x, abs(n))

        return self.pow_recursion(x, n)
