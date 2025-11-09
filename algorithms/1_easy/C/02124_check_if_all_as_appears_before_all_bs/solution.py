class Solution:
    def checkString(self, s: str) -> bool:
        for i in range(1, len(s)):
            if ord(s[i]) < ord(s[i - 1]):
                return False

        return True
