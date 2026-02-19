class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n = len(s)
        curr_count = 1
        prev_count = 0
        res = 0

        for i in range(1, n):
            if s[i] != s[i - 1]:
                res += min(curr_count, prev_count)
                prev_count = curr_count
                curr_count = 1
            else:
                curr_count += 1

        res += min(curr_count, prev_count)

        return res
