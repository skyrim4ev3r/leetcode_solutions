class Solution:
    def makeFancyString(self, s: str) -> str:
        
        repeats = 0
        prev_char = 0
        res = []

        for ch in s:
            if ch == prev_char:
                repeats += 1
            else:
                prev_char = ch
                repeats = 1

            if repeats <= 2:
                res.append(ch)

        return "".join(res)
