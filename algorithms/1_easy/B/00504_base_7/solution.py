class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        res, is_negative = "", False
        if num < 0:
            is_negative = True
            num *= -1
        while num > 0:
            res = str(num % 7) + res
            num //= 7
        if is_negative:
            res = "-" + res
        return res
