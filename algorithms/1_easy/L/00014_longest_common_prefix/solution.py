class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        min_word_len = min(len(word) for word in strs)

        for word_index in range(min_word_len):
            ch = strs[0][word_index]

            for word in strs:
                if word[word_index] != ch:
                    return "".join(word[:word_index])

        return "".join(strs[0][:min_word_len])
