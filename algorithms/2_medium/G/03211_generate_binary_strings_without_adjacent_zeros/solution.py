class Solution:
    def generate_strings_backtrack(self, res,  curr, max_len):
        if len(curr) == max_len:
            res.append("".join(curr))
            return

        if not curr or curr[-1] == '1':
            curr.append('0')
            self.generate_strings_backtrack(res, curr, max_len)
            curr.pop()

        curr.append('1')
        self.generate_strings_backtrack(res, curr, max_len)
        curr.pop()

    def validStrings(self, n: int) -> List[str]:
        res = []
        curr = []
        self.generate_strings_backtrack(res, curr, n)

        return res
