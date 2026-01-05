class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        freqs_bits = [0] * 32
        MOD_TO = 1_000_000_007
        res = 0

        for num in nums:
            freqs_index = 0

            while num > 0:
                if (num & 1) == 1:
                    freqs_bits[freqs_index] += 1

                num = num >> 1
                freqs_index += 1

        max_freq = max(freqs_bits)
        number_of_iter = min(max_freq, k)

        for _ in range(number_of_iter):
            curr = 0

            for i in range(31, -1, -1):
                curr = curr << 1

                if freqs_bits[i] > 0:
                    freqs_bits[i] -= 1
                    curr |= 1

            res = (res + curr * curr) % MOD_TO

        return res
