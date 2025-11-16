class Solution:
    def firstUniqChar(self, s: str) -> int:
        freqs = [[0, 0] for _ in range(26)]
        n = len(s)

        for (i, ch) in enumerate(s):
            char_as_index = ord(ch) - ord('a')

            if freqs[char_as_index][0] == 0:
                freqs[char_as_index][0] = 1
                freqs[char_as_index][1] = i
            else:
                freqs[char_as_index][0] = 2

        res = n

        for count, index in freqs:
            if count == 1:
                res = min(res, index)

        if res == n:
           return  -1

        return res
