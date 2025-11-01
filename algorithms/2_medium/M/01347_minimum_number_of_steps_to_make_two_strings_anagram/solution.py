class Solution:
    def minSteps(self, s: str, t: str) -> int:
        freqs = [0] * 26
        ord_a = ord('a')
        for ch in s:
            freqs[ord(ch) - ord_a] += 1

        for ch in t:
            freqs[ord(ch) - ord_a] -= 1

        # Chars those are in s but not in t will have positive values
        # Chars those are in t but not in s will have negative values
        # Sum of all values will be 0
        # answer is:
        #          sum(abs(freqs)) / 2
        #     or   sum(positive_freqs)
        #     or   abs(sum(negative_freqs))
        #
        # sum(positive_freqs) is more efficent though not noticeable
        total_sum = 0
        for i in range(26):
            if freqs[i] > 0:
                total_sum += freqs[i]

        return total_sum
