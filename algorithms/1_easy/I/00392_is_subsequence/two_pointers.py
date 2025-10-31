class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)

        s_index = 0
        t_index = 0

        while True:
            if s_index == s_len:
                return True

            if t_index == t_len:
                return False

            if s[s_index] == t[t_index]:
                s_index += 1

            t_index += 1
