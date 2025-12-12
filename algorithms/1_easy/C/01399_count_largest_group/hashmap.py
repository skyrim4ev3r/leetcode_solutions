class Solution:
    def countLargestGroup(self, n: int) -> int:
        freqs = defaultdict(int)

        for i in range(1, n + 1):
            temp = i
            dig_sum = 0

            while temp > 0:
                dig_sum += temp % 10
                temp //= 10

            freqs[dig_sum] += 1

        max_freq = 0
        max_freq_count = 0

        for freq in freqs.values():
            if freq > max_freq:
                max_freq = freq
                max_freq_count = 1
            elif freq == max_freq:
                max_freq_count += 1

        return max_freq_count
