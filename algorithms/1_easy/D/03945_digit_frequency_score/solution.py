class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        freqs = [0] * 10

        while n > 0:
            freqs[n % 10] += 1
            n //= 10

        score = 0

        for (i, freq) in enumerate(freqs):
            score += i * freq

        return score
