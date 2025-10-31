class Solution:
    def mySqrt(self, x: int) -> int:

        high = x
        low = 1

        while low <= high:

            mid = low + (high - low) // 2
            square_mid = mid * mid

            if square_mid == x:
                return mid

            if square_mid < x:
                low = mid + 1
            else:
                high = mid - 1

        return low - 1
