class Solution:
    def replaceDigits(self, s: str) -> str:
        n = len(s)
        li = []

        for i in range(1, n, 2):
            li.append(s[i - 1])
            li.append(chr(ord(s[i]) - ord('0') + ord(s[i - 1])))

        if n % 2 == 1:
            li.append(s[-1])

        return "".join(li)
