class Solution:
    def sumOfGoodIntegers(self, n: int, k: int) -> int:
        res = 0

        for x in range(max(n - k, 1), n + k + 1):
            if (x & n) == 0:
                res += x

        return res
