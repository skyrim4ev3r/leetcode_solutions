class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xFFFFFFFF
        MAX_INT = 2**31 - 1

        while b != 0:
            new_b = ((b & a) << 1) & MASK
            a = (a ^ b) & MASK
            b = new_b

        return a if a <= MAX_INT else ~(a ^ MASK)
