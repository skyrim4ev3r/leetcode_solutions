class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False

        n_bin = bin(n)
        if n_bin.count('1') != 1:
            return False

        for i in range(32):
            if (n & (1 << i)) != 0:
                return (i & 1) == 0

        return False
