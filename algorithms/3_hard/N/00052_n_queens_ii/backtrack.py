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

    def backtrack(self, count, board, board_len, curr_row):
        if curr_row == board_len:
            count[0] += 1
            return

        for col in range(board_len):
            if self.is_safe(board, board_len, curr_row, col):
                board[curr_row][col] = 'Q'
                self.backtrack(count, board, board_len, curr_row + 1)
                board[curr_row][col] = '.'

    def totalNQueens(self, n: int) -> int:

        # Uncomment the following lines to use the lookup table for n = 1 to 9 to gain execution speed

        #if 1 <= n <= 9:
        #    return [1, 0, 0, 2, 10, 4, 40, 92, 352][n - 1]
    
        # Backtracking solution

        board = [["." for _ in range(n)] for _ in range(n)]
        count = [0]

        self.backtrack(count, board, n, 0)

        return count[0]
