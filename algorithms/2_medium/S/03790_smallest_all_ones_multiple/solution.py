class Solution:
    def minAllOneMultiple(self, k: int) -> int:
        if k % 2 == 0 or k % 5 == 0:
            return -1

        curr_rem = 0

        for dig_count in range(1, k + 1):
            curr_rem = (curr_rem * 10 + 1) % k

            if curr_rem == 0:
                return dig_count

        return -1
