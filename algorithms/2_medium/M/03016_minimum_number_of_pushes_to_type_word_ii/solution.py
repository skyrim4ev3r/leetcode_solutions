class Solution:
    def minimumPushes(self, word: str) -> int:
        freqs = [0] * 26

        for ch in word:
            freqs[ord(ch) - ord('a')] += 1

        freqs.sort(reverse=True)

        total_cost = 0

        for i in range(len(freqs)):
            curr_cost = 1 + i // 8
            total_cost += freqs[i] * curr_cost

        return total_cost
