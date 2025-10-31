class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) < 2:
            return False

        s_doubled = s + s

        return s in s_doubled[1:-1]
