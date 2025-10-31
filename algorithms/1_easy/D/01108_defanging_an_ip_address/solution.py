class Solution:
    def defangIPaddr(self, address: str) -> str:
        res = []
        for ch in address:
            if ch == '.':
                res.append("[.]")
            else:
                res.append(ch)

        return "".join(res)
