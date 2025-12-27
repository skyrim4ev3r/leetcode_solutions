class Solution:
    def maxDifference(self, s: str) -> int:
        min_even = sys.maxsize
        max_odd = -sys.maxsize
        freqs = [0] * 26

        for ch in s:
            freqs[ord(ch) - ord('a')] += 1

        for freq in freqs:
            if freq > 0:
                if (freq & 1) == 1:
                    max_odd = max(max_odd, freq)
                else:
                    min_even = min(min_even, freq)

        return max_odd - min_even
