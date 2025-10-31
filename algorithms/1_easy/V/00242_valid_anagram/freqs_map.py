class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        freqs_len = 26
        freqs = [0] * freqs_len
        ord_a = ord('a')

        for ch in s:
            freqs[ord(ch) - ord_a] += 1

        for ch in t:
            freqs[ord(ch) - ord_a] -= 1

        for freq in freqs:
            if freq != 0:
                return False

        return True
