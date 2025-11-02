class Solution:
    def isPerfectSquare(self, num: int) -> bool:

        high = num
        low = 1

        while low <= high:

            mid = low + (high - low) // 2
            square_mid = mid * mid

            if square_mid == num:
                return True

            if square_mid < num:
                low = mid + 1
            else:
                high = mid - 1

        return False
