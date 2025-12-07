class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mx = m - 1 if m > n else n - 1
        mn = m - 1 if m < n else n - 1
        high = mx + mn
        res = 1

        for k in range(mx + 1, high + 1):
            res *= k

        for k in range(2, mn + 1):
            res //= k

        return res
