DIRECTIONS = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]
board_size = 8

class Solution:        
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        board = [[False] * board_size for _ in range(board_size)]
        res = []

        for q in queens:
            board[q[0]][q[1]] = True

        i_st = king[0]
        j_st = king[1]

        for (dx, dy) in DIRECTIONS:
            i = i_st + dx
            j = j_st + dy

            while i < board_size and j < board_size and i >= 0 and j >= 0:
                if board[i][j]:
                    res.append([i, j])
                    break

                i = i + dx
                j = j + dy

        return res
