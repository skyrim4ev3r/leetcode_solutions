VALID_BITS_COUNT = 31

class Solution:
    def get_digits_freqs(sellf, n: int) -> List[int]:
        res = [0] * 10

        while n > 0:
            res[n % 10] += 1
            n //= 10

        return res

    def reorderedPowerOf2(self, n: int) -> bool:
        digits_freqs_n = self.get_digits_freqs(n)

        for i in range(VALID_BITS_COUNT):
            digits_freqs_power_of_two = self.get_digits_freqs(1 << i)

            if digits_freqs_n == digits_freqs_power_of_two:
                return True

        return False
