class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        stones = [a, b, c]
        stones.sort()

        [min_s, mid_s, max_s] = stones

        return min((max_s + min_s + mid_s) // 2, min_s + mid_s)
