class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = []
        i1 = len(num1) - 1
        i2 = len(num2) - 1
        carry = 0
        while i1 >= 0 or i2 >= 0:
            ch1 = 0
            if i1 >= 0:
                ch1 = ord(num1[i1]) - ord('0')
                i1 -= 1

            ch2 = 0
            if i2 >= 0:
                ch2 = ord(num2[i2]) - ord('0')
                i2 -= 1

            ch_sum = ch1 + ch2 + carry
            carry = 0
            if ch_sum >= 10:
                carry = 1
                ch_sum -= 10

            res.append(chr(ch_sum + ord('0')))

        if carry > 0:
            res.append(chr(carry + ord('0')))

        res.reverse()

        return "".join(res)
