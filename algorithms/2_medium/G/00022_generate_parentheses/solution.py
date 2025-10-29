class Solution:
    def generate_parenthesis_backtrack(self, tmp_list, n, open_count, close_count):
        if open_count == n and close_count == n:
            self.res.append("".join(tmp_list))
            return

        if open_count < n:
            tmp_list.append('(')
            self.generate_parenthesis_backtrack(tmp_list, n, open_count + 1, close_count);
            tmp_list.pop()

        if close_count < open_count:
            tmp_list.append(')')
            self.generate_parenthesis_backtrack(tmp_list, n, open_count, close_count + 1)
            tmp_list.pop()

    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        tmp_list = []

        self.generate_parenthesis_backtrack(tmp_list, n, 0, 0)

        return self.res

