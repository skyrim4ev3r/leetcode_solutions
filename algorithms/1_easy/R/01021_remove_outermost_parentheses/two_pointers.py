class Solution:
    def removeOuterParentheses(self, s: str) -> str:

        s_len = len(s)
        res = []
        left_index = 0
        open_count = 0
        close_count = 0

        for i in range(s_len):
            if s[i] == '(':
                open_count += 1
            else:
                close_count += 1

            if open_count == close_count:
                res += s[left_index + 1: i]
                left_index = i + 1
                open_count = 0
                close_count = 0

        return "".join(res)
