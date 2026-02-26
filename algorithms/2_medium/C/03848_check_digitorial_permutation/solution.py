class Solution:
    def calc_sum_fact_digit(self, n: int) -> int:
        facts = [0] * 10
        facts[0] = 1
        for i in range(1, 10):
            facts[i] = i * facts[i - 1]

        total_sum = 0

        while n > 0:
            total_sum += facts[n % 10]
            n //= 10

        return total_sum

    def calac_freqs_digits(self, n: int) -> List[int]:
        freqs = [0] * 10
        while n > 0:
            freqs[n % 10] += 1
            n //= 10
        return freqs

    def isDigitorialPermutation(self, n: int) -> bool:
        sum_fact_digit = self.calc_sum_fact_digit(n)

        return self.calac_freqs_digits(n) == self.calac_freqs_digits(sum_fact_digit)
