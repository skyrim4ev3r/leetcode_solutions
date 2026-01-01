class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        seen_upper = [False] * 26
        seen_lower = [False] * 26
        cant_be_count = [False] * 26
        count = 0

        for ch in word:
            if ord(ch) >= ord('A') and ord(ch) <= ord('Z'):
                seen_upper[ord(ch) - ord('A')] = True
            else:
                index = ord(ch) - ord('a')
                seen_lower[index] = True
                if seen_upper[index]:
                    cant_be_count[index] = True
        for i in range(26):
            if seen_lower[i] and seen_upper[i] and cant_be_count[i] == False:
                count += 1

        return count
