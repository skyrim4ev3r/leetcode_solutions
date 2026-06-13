class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        hi = num
        lo = 1

        while lo <= hi:
            mid = lo + (hi - lo) // 2
            square_mid = mid * mid

            if square_mid == num:
                return True

            if square_mid < num:
                lo = mid + 1
            else:
                hi = mid - 1

        return False
