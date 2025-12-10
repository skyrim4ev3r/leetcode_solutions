class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        len1 = len(num1)
        len2 = len(num2)
        res = []

        for i in range(len1):
            carry = 0

            for j in range(len2):
                pos = i + j

                if pos >= len(res):
                    res.append(0)

                curr_val = (ord(num1[len1 - 1 - i]) - ord('0')) * (ord(num2[len2 - 1 - j]) - ord('0')) + carry + res[pos]
                res[pos] =  curr_val % 10
                carry = curr_val // 10

            if carry > 0:
                res.append(carry)

        for i in range(len(res)):
            res[i] = str(res[i])

        res.reverse()

        return "".join(res)
