class Solution:
    def maxFreqSum(self, s: str) -> int:
        ALPHABET_LEN = 26
        frequencies = [0 for _ in range(ALPHABET_LEN)]
        for i in range(len(s)):
            frequencies[ord(s[i]) - ord('a')] += 1

        max_frequency_vowels = 0
        max_frequency_consonants = 0
        for i in range(ALPHABET_LEN):

            if i == 0 or i == 4 or i == 8 or i == 14 or i == 20: # 'a', 'e', 'i', 'o', 'u'
                max_frequency_vowels = max(max_frequency_vowels, frequencies[i])
            else:
                max_frequency_consonants = max(max_frequency_consonants, frequencies[i])

        return max_frequency_consonants + max_frequency_vowels
