class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        has_vowel = False
        has_cons = False

        for ch in word:
            if ord(ch) >= ord('A') and ord(ch) <= ord('Z'):
                if ch in "AEIOU":
                    has_vowel = True
                else:
                    has_cons = True
            elif ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                if ch in "aeiou":
                    has_vowel = True
                else:
                    has_cons = True
            elif ord(ch) >= ord('0') and ord(ch) <= ord('9'):
                continue
            else:
                return False

        return  has_vowel and has_cons
