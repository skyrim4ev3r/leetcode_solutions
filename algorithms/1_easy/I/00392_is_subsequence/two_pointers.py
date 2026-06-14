class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)

        s_idx = 0
        t_idx = 0

        while s_idx < s_len and t_idx < t_len:
            if s[s_idx] == t[t_idx]:
                s_idx += 1

            t_idx += 1

        return s_idx == s_len
