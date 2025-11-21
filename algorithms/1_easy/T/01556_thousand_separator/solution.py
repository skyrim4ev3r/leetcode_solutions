class Solution:
    def thousandSeparator(self, n: int) -> str:
        if n == 0:
            return "0"

        res = []
        dig_count = 0

        while n > 0:
            dig_count += 1
            res.append(chr(n % 10 + ord('0')))
            n //= 10

            if n > 0 and dig_count % 3 == 0:
                res.append('.')

        res.reverse()

        return "".join(res)
