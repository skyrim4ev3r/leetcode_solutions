class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken_letters_set = set(list(brokenLetters))
        count = 0

        for word in text.split():

            had_broken_char = False
            for ch in word:
                if ch in broken_letters_set:
                    had_broken_char = True
                    break

            if not had_broken_char:
                count += 1

        return count
