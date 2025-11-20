class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return -1 if (n | k) != n else bin(n ^ k).count('1')
