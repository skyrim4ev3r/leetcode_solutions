class Solution:
    def is_safe(self, board, board_len, i, j):
        for ofs in range(i + 1):
            if board[i - ofs][j] == 'Q':
                return False

            if j >= ofs and board[i - ofs][j - ofs] == 'Q':
                return False

            if (j + ofs) < board_len and board[i - ofs][j + ofs] == 'Q':
                return False

        return True

    def backtrack(self, res, board, board_len, curr_row):
        if curr_row == board_len:
            curr_board_as_string = []

            for row in board:
               curr_board_as_string.append("".join(row))

            res.append(curr_board_as_string)
            return

        for col in range(board_len):
            if self.is_safe(board, board_len, curr_row, col):
                board[curr_row][col] = 'Q'
                self.backtrack(res, board, board_len, curr_row + 1)
                board[curr_row][col] = '.'

    def solveNQueens(self, n: int) -> List[List[str]]:

        board = [["." for _ in range(n)] for _ in range(n)]
        res = []

        self.backtrack(res, board, n, 0)

        return res
