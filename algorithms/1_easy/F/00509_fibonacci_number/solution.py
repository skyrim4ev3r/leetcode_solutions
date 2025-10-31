class Solution:
    def fib(self, n: int) -> int:
        prev, res = 1, 0
        for i in range(1, n + 1):
            res, prev = res + prev, res
        return res
