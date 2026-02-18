class Solution:
    def calc_product_digits(self, n: int) -> int:
        res = 1

        while n > 0:
            res = res * (n % 10)
            n //= 10

        return res

    def smallestNumber(self, n: int, t: int) -> int:
        # In every 10 consecutive numbers, at least one has the digit 0,
        # ensuring a product of 0, which satisfies the condition 0 % t == 0.
        for i in range(n, n + 10):
            product_digits = self.calc_product_digits(i)

            if product_digits % t == 0:
                return i

        return -1
