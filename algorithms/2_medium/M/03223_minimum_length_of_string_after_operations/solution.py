class Solution:
    def minimumLength(self, s: str) -> int:
        freqs = [0] * 26
        count = 0

        for ch in s:
            freqs[ord(ch) - ord('a')] += 1

        for freq in freqs:
            if freq > 0:
                if (freq & 1) == 1:
                    count += 1
                else:
                    count += 2

        return count
