DIRECTIONS = [(0 , 1), (0, -1), (1, 0), (-1, 0)]

class Solution:
    def dfs(self, board: List[List[str]], m: int, n: int, i: int, j: int):
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'O':
            return

        board[i][j] = 'W'

        for dx, dy in DIRECTIONS:
            self.dfs(board, m, n, i + dx, j + dy)

    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        for j in range(n):
            self.dfs(board, m, n, 0, j)
            self.dfs(board, m, n, m - 1, j)

        for i in range(m):
            self.dfs(board, m, n, i, 0)
            self.dfs(board, m, n, i, n - 1)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'W':
                    board[i][j] = 'O';
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
