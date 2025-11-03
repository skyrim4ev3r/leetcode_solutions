class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        freqs_chars = [0] * 26

        for ch in chars:
            freqs_chars[ord(ch) - ord('a')] += 1

        count = 0

        for word in words:
            freqs = [0] * 26

            for ch in word:
                freqs[ord(ch) - ord('a')] += 1

            is_ans = True
            for i in range(26):
                if freqs[i] > freqs_chars[i]:
                    is_ans = False
                    break

            if is_ans:
                count += len(word)

        return count
