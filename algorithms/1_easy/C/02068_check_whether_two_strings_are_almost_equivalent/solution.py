class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        freqs = [0] * 26

        for ch in word1:
            freqs[ord(ch) - ord('a')] += 1

        for ch in word2:
            freqs[ord(ch) - ord('a')] -= 1

        for freq in freqs:
            if abs(freq) > 3:
                return False

        return True
