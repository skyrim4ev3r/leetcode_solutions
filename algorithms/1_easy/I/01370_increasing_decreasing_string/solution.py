class Solution:
    def sortString(self, s: str) -> str:
        freqs = [0] * 26
        res = []
        for ch in s:
            freqs[ord(ch) - ord('a')] += 1

        flip_flop = True
        while len(res) != len(s):
            if flip_flop:
                for i in range(26):
                    if freqs[i] > 0:
                        freqs[i] -= 1
                        res.append(chr(i + ord('a')))
            else:
                for i in range(25, -1, -1):
                    if freqs[i] > 0:
                        freqs[i] -= 1
                        res.append(chr(i + ord('a')))

            flip_flop = not flip_flop

        return "".join(res)
