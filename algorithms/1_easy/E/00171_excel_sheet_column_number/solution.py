class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        count, mul, ch_before_A = 0, 1, ord('A') - 1
        for i in range(len(columnTitle) - 1, -1,-1):
            count += (ord(columnTitle[i]) - ch_before_A) * mul
            mul *= 26
        return count
