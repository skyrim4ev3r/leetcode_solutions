INT_MAX = 2 ** 31
INT_MIN = -INT_MAX - 1

class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        x_abs = abs(x)

        while x_abs != 0:
            rev = rev * 10 + x_abs % 10
            x_abs //= 10

        if x < 0:
            rev *= -1

        if rev > INT_MAX or rev < INT_MIN:
            return 0

        return rev
