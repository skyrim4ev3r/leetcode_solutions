class Solution:
    def convertToTitle(self, col_number: int) -> str:
        res = []

        while col_number >= 1:
            rem = (col_number - 1) % 26
            res.append(chr(rem + ord('A')))
            col_number = (col_number - 1) // 26

        res.reverse()

        return "".join(res)
