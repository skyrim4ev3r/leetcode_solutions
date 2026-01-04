class Solution:
    def minimumPushes(self, word: str) -> int:
        freqs = [0] * 26

        for ch in word:
            freqs[ord(ch) - ord('a')] += 1

        freqs.sort(reverse=True)

        return (
            sum(freqs[0:8]) +
            sum(freqs[8:16]) * 2 +
            sum(freqs[16:24]) * 3 +
            sum(freqs[24:26]) * 4
        )
