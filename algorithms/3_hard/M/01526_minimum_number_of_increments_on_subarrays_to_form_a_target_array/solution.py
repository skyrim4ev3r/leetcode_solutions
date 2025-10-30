class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        total = target[0]
        for i in range(1, len(target)):
            total += max(0, target[i] - target[i - 1])

        return total
