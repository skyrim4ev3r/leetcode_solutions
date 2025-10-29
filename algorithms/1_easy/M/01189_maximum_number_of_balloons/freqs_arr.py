class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freqs = [0] * 26

        for ch in text:
            freqs[ord(ch) - ord('a')] += 1

        return min([freqs[ord('b') - ord('a')], \
                    freqs[ord('a') - ord('a')], \
                    freqs[ord('l') - ord('a')] // 2, \
                    freqs[ord('o') - ord('a')] // 2, \
                    freqs[ord('n') - ord('a')]])
