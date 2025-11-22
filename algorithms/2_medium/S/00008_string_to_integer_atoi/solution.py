class Solution:
    def myAtoi(self, s: str) -> int:
        n = len(s)
        is_negative = False
        index = 0
        INT_MIN = -(2 ** 31)
        INT_MAX = (2 ** 31) - 1

        while index < n and s[index] == ' ':
            index += 1

        if index == n:
            return 0

        if s[index] == '-':
            is_negative = True

        if s[index] == '-' or s[index] == '+':
            index += 1

        res = 0

        while index < n and ord(s[index]) >= ord('0') and ord(s[index]) <= ord('9'):
            res *= 10
            res += ord(s[index]) - ord('0')
            index += 1;

            if is_negative and res * -1 < INT_MIN:
                return INT_MIN

            if not is_negative and res > INT_MAX:
                return INT_MAX

        if is_negative:
            return res * -1

        return res
