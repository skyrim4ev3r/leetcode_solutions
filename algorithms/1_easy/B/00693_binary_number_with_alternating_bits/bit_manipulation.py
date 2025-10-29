class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev_remainder = -1

        while n > 0:
            curr_remainder = n & 1
            if curr_remainder == prev_remainder:
                return False

            prev_remainder = curr_remainder
            n = (n >> 1)

        return True
