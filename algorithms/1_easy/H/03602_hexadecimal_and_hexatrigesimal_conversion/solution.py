class Solution:
    def to_custom_base(self, num: int, base: int) -> str:
        if num == 0:
            return "0"

        res = []

        while num > 0:
            remainder = num % base
            if remainder < 10:
                res.append(chr(remainder + ord('0')))
            else:
                res.append(chr(remainder - 10 + ord('A')))

            num //= base

        res.reverse()

        return "".join(res)

    def concatHex36(self, n: int) -> str:
        return "{}{}".format(
            self.to_custom_base(n * n, 16),
            self.to_custom_base(n * n * n, 36)
        )
