class Solution:
    def addBinary(self, a: str, b: str) -> str:

        a = list(a)
        b = list(b)

        carry = 0
        ord_0 = ord('0')

        if len(a) < len(b):
            a, b = b, a

        for i in range(len(a) - 1, -1, -1):

            b_char = '0'

            if b:
                b_char = b.pop()

            bit_sum = (ord(a[i]) - ord_0) + (ord(b_char) - ord_0) + carry
            carry = 0
            if bit_sum > 1:
                bit_sum -= 2
                carry = 1

            a[i] = chr(bit_sum + ord_0)

            if carry == 0 and not b:
                break

        if carry == 1:
            a.insert(0, '1')

        return "".join(a)
