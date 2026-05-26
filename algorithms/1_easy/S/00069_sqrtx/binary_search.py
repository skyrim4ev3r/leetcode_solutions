class Solution:
    def mySqrt(self, x: int) -> int:
        high = x
        low = 0

        while low <= high:
            mid = low + (high - low) // 2

            if mid ** 2 <= x:
                low = mid + 1
            else:
                high = mid - 1

        return high
