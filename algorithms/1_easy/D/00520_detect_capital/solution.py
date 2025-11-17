class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        is_capital = True
        is_lower = True
        is_upper = True

        for i, ch in enumerate(word):
            if i == 0:
                if ch.islower():
                    is_capital = False
                    is_upper = False
                else:
                    is_lower = False
            else:
                if ch.islower():
                    is_upper = False
                else:
                    is_capital = False
                    is_lower = False

            if not is_capital and not is_lower and not is_upper:
                return False

        return True
