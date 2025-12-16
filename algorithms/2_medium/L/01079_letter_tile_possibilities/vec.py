class Solution:
    def backtrack(self, freqs, n):
        count = 0

        for i in range(n):
            if freqs[i] != 0:
                freqs[i] -= 1
                count += 1 + self.backtrack(freqs, n)
                freqs[i] += 1

        return count

    def numTilePossibilities(self, tiles: str) -> int:
        freqs = [0] * 26

        for ch in tiles:
            freqs[ord(ch) - ord('A')] += 1

        valid_freqs = []

        for freq in freqs:
            if freq > 0:
                valid_freqs.append(freq)

        return self.backtrack(valid_freqs, len(valid_freqs))
