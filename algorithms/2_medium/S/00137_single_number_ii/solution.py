INPUT_BITS = 32

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        freqs_bits = [0] * INPUT_BITS
        negative_count = 0

        for num in nums:
            if num < 0:
                negative_count += 1

            for i in range(INPUT_BITS):
                if (abs(num) & (1 << i)) != 0:
                    freqs_bits[i] += 1

        for (i, freq) in enumerate(freqs_bits):
            if freq % 3 != 0:
                res |= (1 << i)

        return res * (-1 if negative_count % 3 != 0 else 1)
