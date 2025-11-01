class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        s = list(s)
        t = list(t)

        s_len = len(s)
        t_len = len(t)

        s_index = 0
        t_index = 0

        while s_index < s_len and t_index < t_len:
            if s[s_index] == t[t_index]:
                t_index += 1

            s_index += 1

        return t_len - t_index
