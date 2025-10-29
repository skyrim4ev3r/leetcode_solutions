class Solution:
    def helper(self, s, left, right):
        while left > 0 and right < self.len - 1 and s[left - 1] == s[right + 1]:
            left -= 1
            right += 1

        width = right - left + 1

        if width > self.max_width:
            self.max_width = width
            self.max_start_idx = left

    def longestPalindrome(self, s: str) -> str:
        self.max_width = 0
        self.max_start_idx = 0
        self.len = len(s)

        for i in range(self.len):
            if i > 0 and s[i - 1] == s[i]:
                self.helper(s, i - 1, i)
            self.helper(s, i, i)
        return s[self.max_start_idx : self.max_start_idx + self.max_width]
