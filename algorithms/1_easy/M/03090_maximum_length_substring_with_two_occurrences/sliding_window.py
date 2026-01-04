class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        n = len(s)
        window_freqs = [0] * 26
        left = 0
        res = 0

        for right in range(n):
            index = ord(s[right]) - ord('a')
            window_freqs[index] += 1

            while window_freqs[index] > 2:
                window_freqs[ord(s[left]) - ord('a')] -= 1
                left += 1

            res = max(res, right + 1 - left)

        return res
