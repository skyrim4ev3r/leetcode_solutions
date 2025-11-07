class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:

        s_len = len(s)
        s_index = 0

        for word in words:

            word_len = len(word)
            w_index = 0

            if word_len > s_len - s_index:
                return False

            while w_index < word_len and word[w_index] == s[s_index]:
                s_index += 1
                w_index += 1

            if w_index != word_len:
                return False

            if s_index == s_len:
                return True

        return False
