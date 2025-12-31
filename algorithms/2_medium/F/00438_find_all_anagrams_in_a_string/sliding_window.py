class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []

        p_len = len(p)
        s_len = len(s)
        freqs_window_s = [0] * 26
        freqs_p = [0] * 26
        res = []

        for i in range(p_len):
            freqs_p[ord(p[i]) - ord('a')] += 1
            freqs_window_s[ord(s[i]) - ord('a')] += 1

        if freqs_window_s == freqs_p:
            res.append(0)

        for i in range(s_len - p_len):
            freqs_window_s[ord(s[i]) - ord('a')] -= 1
            freqs_window_s[ord(s[i + p_len]) - ord('a')] += 1

            if freqs_window_s == freqs_p:
                res.append(i + 1)

        return res
