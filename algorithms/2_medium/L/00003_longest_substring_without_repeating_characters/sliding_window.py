MAP_LEN = 256

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        last_seen = [-1] * MAP_LEN
        longest_substr = 0
        lo = 0

        for hi in range(n):
            idx_last_seen = ord(s[hi])
            lo = max(lo, last_seen[idx_last_seen] + 1)
            longest_substr = max(longest_substr, hi - lo + 1)
            last_seen[idx_last_seen] = hi

        return longest_substr
