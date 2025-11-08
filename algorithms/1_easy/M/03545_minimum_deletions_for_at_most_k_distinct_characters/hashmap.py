class Solution:
    def minDeletion(self, s: str, k: int) -> int:
        return sum(sorted(list(Counter(s).values()), reverse=True)[k:])
