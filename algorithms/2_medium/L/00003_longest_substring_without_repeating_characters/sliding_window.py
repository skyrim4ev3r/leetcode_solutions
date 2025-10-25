class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        s_len = len(s)
        last_seen_index = [s_len] * 128
        max_len = 0
        left = 0

        for right in range(s_len):

            char_index = ord(s[right])

            if last_seen_index[char_index] < s_len:
                left = max(left, last_seen_index[char_index] + 1)

            last_seen_index[char_index] = right

            max_len = max(max_len, right - left + 1)

        return max_len
