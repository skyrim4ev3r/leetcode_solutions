class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        n = len(s1)
        balance_freqs_even_indices = [0] * 26
        balance_freqs_odd_indices = [0] * 26

        for i in range(n):
            if (i & 1) == 0:
                balance_freqs_even_indices[ord(s1[i]) - ord('a')] += 1
                balance_freqs_even_indices[ord(s2[i]) - ord('a')] -= 1
            else:
                balance_freqs_odd_indices[ord(s1[i]) - ord('a')] += 1
                balance_freqs_odd_indices[ord(s2[i]) - ord('a')] -= 1

        for i in range(26):
            if balance_freqs_even_indices[i] != 0 or balance_freqs_odd_indices[i] != 0:
                return False

        return True
