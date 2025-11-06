class Solution:
    def finalString(self, s: str) -> str:

        res = []
        should_reverse = False

        for ch in s:
            if ch == 'i':
                should_reverse = not should_reverse
            else:
                if should_reverse:
                    res.reverse()
                    should_reverse = False
                res.append(ch)

        if should_reverse:
            res.reverse()

        return "".join(res)
