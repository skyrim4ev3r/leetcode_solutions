class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        longest = 0

        for i in range(n):
            freqs = [0] * 26

            for j in range(i, n):
                freq_index = ord(s[j]) - ord('a')
                freqs[freq_index] += 1
                curr_freq = freqs[freq_index]

                if all(freq == 0 or freq == curr_freq for freq in freqs):
                    longest = max(longest, j - i + 1)

        return longest
