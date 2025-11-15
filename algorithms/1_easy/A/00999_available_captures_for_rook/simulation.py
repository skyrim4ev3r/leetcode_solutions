DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        n = 8

        for i in range(n):
            for j in range(n):
                if board[i][j] == 'R':
                    count = 0

                    for (dx, dy) in DIRECTIONS:
                        new_i = i + dx
                        new_j = j + dy

                        while new_i >= 0 and new_j >= 0 and new_i < n and new_j < n and board[new_i][new_j] == '.':
                            new_i += dx
                            new_j += dy

                        if new_i >= 0 and new_j >= 0 and new_i < n and new_j < n and board[new_i][new_j] == 'p':
                            count += 1

                    return count

        return -1
