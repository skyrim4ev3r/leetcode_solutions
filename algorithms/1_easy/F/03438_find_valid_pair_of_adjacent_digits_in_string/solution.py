class Solution:
    def findValidPair(self, s: str) -> str:
        freqs = [0] * 10
        n = len(s)

        for ch in s:
            freqs[ord(ch) - ord('0')] += 1

        for i in range(n - 1):
            if (
                s[i] != s[i + 1] and
                ord(s[i]) - ord('0') == freqs[ord(s[i]) - ord('0')] and
                ord(s[i + 1]) - ord('0') == freqs[ord(s[i + 1]) - ord('0')]
            ):
                return s[i] + s[i + 1]

        return ""
