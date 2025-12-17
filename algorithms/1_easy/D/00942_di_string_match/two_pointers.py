class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        max_val = len(s)
        min_val = 0
        res = []

        for ch in s:
            if ch == 'D':
                res.append(max_val)
                max_val -= 1
            else:
                res.append(min_val)
                min_val += 1

        res.append(min_val)

        return res
