class Solution:
    def minPartitions(self, n: str) -> int:
        return ord(max(list(n))) - ord('0')
