class Solution:
    def minimumCost(self, c1: int, c2: int, cb: int, n1: int, n2: int) -> int:
        return min(c1 * n1 + c2 * n2, min(n1, n2) * cb + min(abs(n2 - n1) * cb, c2 * (n2 - n1) if n2 > n1 else c1 * (n1 - n2)))
