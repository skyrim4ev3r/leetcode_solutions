class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        half = k // 2
        cnt_l = min(n, half); # number of nums to select where num < k
        cnt_r = max(0, n - half); # number of nums to select where num >= k

        sum_l = (cnt_l * (cnt_l + 1)) // 2
        sum_r = cnt_r * (k - 1) + (cnt_r * (cnt_r + 1)) // 2

        return sum_l + sum_r
