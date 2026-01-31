class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        freqs = [0] * 26
        used = [False] * 26
        res = []

        for ch in s:
            freqs[ord(ch )- ord('a')] += 1

        for ch in s:
            index = ord(ch )- ord('a')
            freqs[index] -= 1

            if not used[index]:
                while res and ord(res[-1]) > ord(ch):
                    index_last = ord(res[-1])- ord('a')

                    if freqs[index_last] == 0:
                        break

                    used[index_last] = False
                    res.pop()

                res.append(ch)
                used[index] = True

        return "".join(res)
