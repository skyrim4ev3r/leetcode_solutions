class Solution:
    def possibleStringCount(self, word: str) -> int:
        n = len(word)
        res = 0

        for i in range(1, n):
            if word[i] == word[i - 1]:
                res += 1

        # The total count of segments is the number of duplicates found (res) plus one
        # for the initial group of characters in the string
        return res + 1
