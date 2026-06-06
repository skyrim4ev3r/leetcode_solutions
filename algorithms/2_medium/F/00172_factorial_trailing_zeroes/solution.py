class Solution:
    def trailingZeroes(self, n: int) -> int:
        cnt_five = 0
        div = 5

        while div <= n:
            cnt_five += n // div
            div *= 5

        return cnt_five
