class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        freqs = [0] *26
        left = 0
        curr_max_freq = 0
        res = 0

        for right in range(n):
            total = right - left + 1
            freqs[ord(s[right]) - ord('A')] += 1
            curr_max_freq = max(curr_max_freq, freqs[ord(s[right]) - ord('A')])

            if total - curr_max_freq > k:
                freqs[ord(s[left]) - ord('A')] -= 1
                left += 1
            else:
                res = total

        return res
