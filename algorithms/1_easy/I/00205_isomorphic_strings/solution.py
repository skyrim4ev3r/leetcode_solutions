class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        first_seen_s = [-1] * 128
        first_seen_t = [-1] * 128
        n = len(s)

        for i in range(n):
            ch_s_as_index = ord(s[i])
            ch_t_as_index = ord(t[i])

            if first_seen_s[ch_s_as_index] == -1:
                first_seen_s[ch_s_as_index] = i

            if first_seen_t[ch_t_as_index] == -1:
                first_seen_t[ch_t_as_index] = i

            if first_seen_s[ch_s_as_index] != first_seen_t[ch_t_as_index]:
                return False

        return True
