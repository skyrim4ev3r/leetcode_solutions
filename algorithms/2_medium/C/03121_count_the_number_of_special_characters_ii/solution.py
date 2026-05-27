class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        upper = [False] * 26
        lower = [False] * 26
        lower_after_upper = [False] * 26

        for ch in word:
            if ord(ch) >= ord('A') and ord(ch) <= ord('Z'):
                upper[ord(ch) - ord('A')] = True
            else:
                index = ord(ch) - ord('a')
                lower[index] = True
                if upper[index]:
                    lower_after_upper[index] = True

        count = 0

        for i in range(26):
            if lower[i] and upper[i] and lower_after_upper[i] == False:
                count += 1

        return count
