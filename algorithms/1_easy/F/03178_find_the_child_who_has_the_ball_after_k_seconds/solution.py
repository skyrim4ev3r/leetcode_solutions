class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        k %= 2 * (n - 1)

        if k < n:
            return k
        else:
            return n - 2 - (k - n)
