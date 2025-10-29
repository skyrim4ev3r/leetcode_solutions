class Solution:
    def minChanges(self, s: str) -> int:
        s_len = len(s)
        count = 0

        for index in range(1, s_len, 2):
            if s[index] != s[index - 1]:
                count += 1

        return count
