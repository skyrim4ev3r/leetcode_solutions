class Solution:
    def numberOfMatches(self, n: int) -> int:
        count = 0

        while n > 1:
            count += n // 2

            if (n & 1) == 1:
                n = 1 + n // 2
            else:
                n //= 2

        return count
