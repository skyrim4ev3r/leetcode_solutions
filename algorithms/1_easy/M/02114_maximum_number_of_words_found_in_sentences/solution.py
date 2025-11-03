class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        max_word = 0

        for sentence in sentences:
            count = 1
            for ch in sentence:
                if ch == ' ':
                    count += 1

            max_word = max(count, max_word)

        return max_word
