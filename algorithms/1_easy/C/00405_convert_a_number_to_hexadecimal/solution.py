class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"

        u_num = num & 0xFFFFFFFF
        res = []

        while u_num > 0:
            curr_dig = u_num % 16
            u_num //= 16

            if curr_dig >= 10:
                res.append(chr(curr_dig - 10 + ord('a')))
            else:
                res.append(chr(curr_dig + ord('0')))

        res.reverse()
        return "".join(res)
