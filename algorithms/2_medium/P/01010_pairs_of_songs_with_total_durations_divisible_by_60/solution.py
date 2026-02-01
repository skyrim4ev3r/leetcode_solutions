class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freqs = [0] * 60
        res = 0

        for t in time:
            curr = t % 60
            other = (60 - curr) % 60
            freq_other = freqs[other]

            res += freq_other
            freqs[curr] += 1

        return res
