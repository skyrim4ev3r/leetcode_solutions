class Solution:
    def sortVowels(self, s):
        vowels = "aeiouAEIOU"

        # Extract vowels from the string and sorting it
        vowels_in_s = [ch for ch in s if ch in vowels]
        vowels_in_s.sort()

	    # Converting to list for mutability
        s_list = list(s)

	    # Foreach vowel in s_list replace it by sorted vowels 1 by 1
        vowels_in_s_index = 0
        for i in range(len(s_list)):
            if s_list[i] in vowels:
                s_list[i] = vowels_in_s[vowels_in_s_index]
                vowels_in_s_index += 1

        return ''.join(s_list)
