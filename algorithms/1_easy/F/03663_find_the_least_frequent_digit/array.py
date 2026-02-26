class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        freqs = [0] * 10

        while n > 0:
            freqs[n % 10] += 1
            n //= 10

        min_freq = sys.maxsize
        min_freq_index = 0

        for i in range(10):
            if freqs[i] != 0 and freqs[i] < min_freq:
                min_freq = freqs[i]
                min_freq_index = i

        return min_freq_index
