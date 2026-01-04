class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        freqs = [0] * 26

        for ch in s:
            freqs[ord(ch) - ord('a')] += 1

        m = max(freqs)

        for i in range(26):
            freqs[i] = max(0, freqs[i] - m + 1)

        res = []

        for ch in reversed(s):
            if freqs[ord(ch) - ord('a')] > 0:
                freqs[ord(ch) - ord('a')] -= 1
                res.append(ch)

        res.reverse()

        return "".join(res)
