class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word1_list = list(word1)
        word2_list = list(word2)
        len1 = len(word1)
        len2 = len(word2)

        res = []

        min_len = min(len1, len2)

        for index in range(min_len):
            res.append(word1_list[index])
            res.append(word2_list[index])

        res += word1_list[min_len:len1]
        res += word2_list[min_len:len2]

        return "".join(res)
