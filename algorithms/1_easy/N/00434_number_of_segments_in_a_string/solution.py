class Solution:
    def countSegments(self, s: str) -> int:
        segments = 0
        n = len(s)

        for i in range(n):
            if s[i] != ' ' and (i == 0 or s[i - 1] == ' '):
                segments += 1

        return segments
