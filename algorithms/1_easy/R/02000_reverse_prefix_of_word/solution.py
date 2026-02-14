class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        index = word.find(ch)

        if index != -1:
            prefix = word[:index + 1][::-1]
            return prefix + word[index + 1:]

        return word
