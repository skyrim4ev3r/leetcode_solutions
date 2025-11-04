#
#	O(m + n)        nested loop wont add complexity
#

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        freqs_len = 26

        freqs = [0] * freqs_len
        res = []
        ord_a = ord('a')

        for ch in s:
            freqs[ord(ch) - ord_a] += 1

        for ch in order:

            freq_index = ord(ch) - ord_a
            freq = freqs[freq_index]
            freqs[freq_index] = 0

            for _ in range(freq):
                res.append(ch)

        for i in range(freqs_len):
            if freqs[i] > 0:
                ch = chr(i + ord_a)
                for _ in range(freqs[i]):
                    res.append(ch)

        return "".join(res)
