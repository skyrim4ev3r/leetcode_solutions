class Solution:
    def minimumSteps(self, s: str) -> int:
        zeros_count = 0
        cost = 0

        for (i, ch) in enumerate(s):
            if ch == '0':
                cost += (i - zeros_count)
                zeros_count += 1

        return cost
