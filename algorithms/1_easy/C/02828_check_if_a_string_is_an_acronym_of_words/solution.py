class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        if len(s) != len(words):
            return False

        for (i, word) in enumerate(words):
            if s[i] != word[0]:
                return False

        return True
