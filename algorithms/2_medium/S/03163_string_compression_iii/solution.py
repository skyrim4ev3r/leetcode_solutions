class Solution:
    def compressedString(self, word: str) -> str:
        n = len(word)
        res = []
        count = ord('0')

        for i in range(n):
            if i > 0 and word[i] == word[i - 1]:
                count += 1
            else:
                if count > ord('0'):
                    res.append(chr(count))
                    res.append(word[i - 1])

                count = ord('1')

            if count == ord('9') or i == n - 1:
                res.append(chr(count))
                res.append(word[i])
                count = ord('0')

        return "".join(res)
