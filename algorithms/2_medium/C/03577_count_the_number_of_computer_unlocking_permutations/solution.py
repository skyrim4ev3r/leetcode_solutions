MOD_TO = 1_000_000_007

class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        n = len(complexity)

        for i in range(1, n):
            if complexity[i] <= complexity[0]:
                return 0

        count = 1

        for i in range(2, n):
            count = (count * i) % MOD_TO

        return count
