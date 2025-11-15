class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freqs = [0] * 26

        for ch in magazine:
            freqs[ord(ch) - ord('a')] += 1

        for ch in ransomNote:
            index = ord(ch) - ord('a')

            if freqs[index] == 0:
                return False

            freqs[index] -= 1

        return True
