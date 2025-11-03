class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = []
        prev_word = ""

        for word in words:
            word_sorted = list(word)
            word_sorted.sort()
            if prev_word != word_sorted:
                res.append(word)
                prev_word = word_sorted

        return res
