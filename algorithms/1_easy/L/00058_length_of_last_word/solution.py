class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        curr_word_len = 0
        last_word_len = 0

        for ch in s:
            if ch == ' ':
                curr_word_len = 0
            else:
                curr_word_len += 1
                last_word_len = curr_word_len

        return last_word_len
