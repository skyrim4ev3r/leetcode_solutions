class Solution:
    def stringSequence(self, target: str) -> List[str]:

        screen = []
        res = []

        for ch in target:
            screen.append(chr(0))

            for last_ch in  range(ord('a'), ord(ch) + 1):
                screen[-1] = chr(last_ch)
                res.append("".join(screen))

        return res
