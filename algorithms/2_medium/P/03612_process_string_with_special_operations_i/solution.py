class Solution:
    def processStr(self, s: str) -> str:
        res = []
        for ch in s:
            if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                res.append(ch)
            elif ch == '#':
                res += res
            elif ch == '%':
                res.reverse()
            else:
                if res:
                    res.pop()

        return ''.join(res)
