MAX_SIZE = 128

class Solution:
    def frequencySort(self, s: str) -> str:
        res = []
        freqs = [[0, chr(x)] for x in range(MAX_SIZE)]

        for ch in s:
            freqs[ord(ch)][0] += 1
        freqs = [x for x in freqs if x[0] != 0]
        freqs.sort(reverse=True)

        for (count, ch) in freqs:
            for _ in range(count):
                res.append(ch)

        return "".join(res)
