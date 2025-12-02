class Solution:
    def maxDistinct(self, s: str) -> int:
        is_seen = [False] * 26

        for ch in s:
            is_seen[ord(ch) - ord('a')] = True

        return is_seen.count(True)
