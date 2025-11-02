class Solution:
    def arrangeCoins(self, n: int) -> int:

        x = n * 2
        y = int(sqrt(x))

        if y * (y + 1) > x:
            y -= 1

        return y
