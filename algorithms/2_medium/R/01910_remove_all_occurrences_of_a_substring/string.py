class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        part_len = len(part)

        pos = s.find(part)
        while pos != -1:
            s = s[:pos] + s[pos + part_len:]
            pos = s.find(part)

        return s
