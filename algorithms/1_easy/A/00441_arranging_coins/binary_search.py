class Solution:
    def arrangeCoins(self, n: int) -> int:

        low = 1
        high = n

        while low <= high:

            mid = low + (high - low) // 2
            curr_sum = (mid * (mid + 1)) // 2

            if curr_sum == n:
                return mid

            if curr_sum < n:
                low = mid + 1
            else:
                high = mid - 1

        return low - 1
