class Solution:
    def mirrorDistance(self, n: int) -> int:
        temp = n
        rev_n = 0

        while temp > 0:
            rev_n = rev_n * 10 + temp % 10
            temp //= 10

        return abs(n - rev_n)
