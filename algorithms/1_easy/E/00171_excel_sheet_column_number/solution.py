class Solution:
    def titleToNumber(self, col_title: str) -> int:
        count = 0

        for ch in col_title:
            count = count * 26 + (ord(ch) - (ord('A') - 1))

        return count
