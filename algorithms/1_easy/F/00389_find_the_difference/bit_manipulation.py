class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        added_char = 0

        for  ch in s:
            added_char ^= ord(ch)

        for  ch in t:
            added_char ^= ord(ch)

        return chr(added_char)
