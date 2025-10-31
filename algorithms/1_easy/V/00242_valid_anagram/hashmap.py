class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        freqs = {}

        for ch in s:
            if ch in freqs:
                freqs[ch] += 1
            else:
                freqs[ch] = 1

        for ch in t:
            if ch in freqs:
                freqs[ch] -= 1
            else:
                return False

        for freq in freqs.values():
            if freq != 0:
                return False

        return True
