class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res = []
        flags = [0] * 128

        for ch in "qwertyuiopQWERTYUIOP":
            flags[ord(ch)] = 1

        for ch in "asdfghjklASDFGHJKL":
            flags[ord(ch)] = 2

        for ch in "zxcvbnmZXCVBNM":
            flags[ord(ch)] = 4

        for word in words:
            flag = 0
            for ch in word:
                flag |= flags[ord(ch)]

                if flag != 1 and flag != 2 and flag != 4:
                    break

            if flag == 1 or flag == 2 or flag == 4:
                res.append(word)

        return res
