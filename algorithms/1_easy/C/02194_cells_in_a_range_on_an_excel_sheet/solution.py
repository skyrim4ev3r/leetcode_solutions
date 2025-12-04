class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        curr = list(s[0:2])
        target = list(s[3:5])
        res = ["".join(curr)]
        start_row = ord(s[1])
        end_row = ord(s[4])

        while curr != target:
            curr[1] = chr(ord(curr[1]) + 1)

            if ord(curr[1]) > end_row:
                curr[1] = chr(start_row)
                curr[0] = chr(ord(curr[0]) + 1)

            res.append("".join(curr))

        return res
