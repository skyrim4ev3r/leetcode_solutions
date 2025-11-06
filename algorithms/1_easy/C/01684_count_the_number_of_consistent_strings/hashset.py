class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed_chars = set(list(allowed))
        count = 0

        for word in words:
            is_good = True

            for ch in word:
                if ch not in allowed_chars:
                    is_good = False
                    break

            if is_good:
                count += 1

        return count
