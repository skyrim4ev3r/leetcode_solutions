class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        ord_1 = ord('1')

        # Check all rows are valid
        for i in range(9):
            is_seen = [False] * 9
            for j in range(9):
                if board[i][j] != '.':
                    is_seen_index = ord(board[i][j]) - ord_1
                    if is_seen[is_seen_index]:
                        return False
                    is_seen[is_seen_index] = True

        # Check all cols are valid
        for j in range(9):
            is_seen = [False] * 9
            for i in range(9):
                if board[i][j] != '.':
                    is_seen_index = ord(board[i][j]) - ord_1
                    if is_seen[is_seen_index]:
                        return False
                    is_seen[is_seen_index] = True

       # Check all 3*3 sub-boxes
        for cell in range(9):

            is_seen = [False] * 9
            start_i = (cell // 3) * 3
            start_j = (cell % 3) * 3

            for i in range(start_i, start_i + 3):
                for j in range(start_j, start_j + 3):
                    if board[i][j] != '.':
                        is_seen_index = ord(board[i][j]) - ord_1
                        if is_seen[is_seen_index]:
                            return False
                        is_seen[is_seen_index] = True

        return True
