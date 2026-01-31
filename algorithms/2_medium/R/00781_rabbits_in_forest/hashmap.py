class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        freqs = Counter(answers)
        count = 0

        for (val, freq) in freqs.items():
            group_count = (freq + val) // (val + 1)
            count += group_count * (val + 1)

        return count
