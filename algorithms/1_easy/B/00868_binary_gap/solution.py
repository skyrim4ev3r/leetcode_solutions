BITS_COUNT = 32

class Solution:
    def binaryGap(self, n: int) -> int:
        prev_valid_bit = (0, False)
        max_dist = 0

        for i in range(BITS_COUNT):
            mask = 1 << i

            if (mask & n) != 0:
                if prev_valid_bit[1]:
                    max_dist = max(max_dist, i - prev_valid_bit[0])

                prev_valid_bit = (i, True)

        return max_dist
