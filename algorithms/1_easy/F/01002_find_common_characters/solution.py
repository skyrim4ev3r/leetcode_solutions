class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        max_freqs = [sys.maxsize] * 26

        for word in words:
            freqs = [0] * 26

            for ch in word:
                freqs[ord(ch) - ord('a')] += 1

            for i in range(26):
                max_freqs[i]= min(max_freqs[i], freqs[i])

        res = []
        for i in range(26):
            temp = chr(i + ord('a'))

            for _ in range(max_freqs[i]):
                res.append(temp)

        return res
