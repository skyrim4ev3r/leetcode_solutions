class Solution:
    def longestPalindrome(self, s: str) -> int:
        freqs_upper = [0] * 26
        freqs_lower = [0] * 26

        for ch in s:
            if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                freqs_lower[ord(ch) - ord('a')] += 1
            else:
                freqs_upper[ord(ch) - ord('A')] += 1

        count = 0
        any_odd = False

        for freq in freqs_lower:
            if (freq & 1) == 1:
                count += freq - 1
                any_odd = True
            else:
                count += freq

        for freq in freqs_upper:
            if (freq & 1) == 1:
                count += freq - 1
                any_odd = True
            else:
                count += freq

        if any_odd:
            count += 1

        return count
