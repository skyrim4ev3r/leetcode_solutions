class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        freqs = [0] * 24
        count = 0

        for h in hours:
            freqs[h % 24] += 1

        count += freqs[0] * (freqs[0] - 1) // 2
        count += freqs[12] * (freqs[12] - 1) // 2

        for i in range(1, 12):
            count += freqs[i] * freqs[24 - i]

        return count
