class Solution:
    def lastRemaining(self, n: int) -> int:
        hi = n
        lo = 1
        steps = 1
        lo_to_hi = True

        while lo < hi:
            cnt = ((hi - lo + 1) + (steps - 1)) // steps

            if lo_to_hi:
                lo += steps
                if (cnt & 1) == 1:
                    hi -= steps
            else:
                hi -= steps
                if (cnt & 1) == 1:
                    lo += steps

            steps *= 2
            lo_to_hi = not lo_to_hi

        return lo
