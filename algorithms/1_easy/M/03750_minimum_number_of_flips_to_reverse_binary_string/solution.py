class Solution:
    def minimumFlips(self, n: int) -> int:
        rev = 0
        temp = n

        while temp > 0:
            rev = rev << 1

            if (temp & 1) == 1:
                rev |= 1

            temp = temp >> 1

        return bin(rev ^ n).count('1')
