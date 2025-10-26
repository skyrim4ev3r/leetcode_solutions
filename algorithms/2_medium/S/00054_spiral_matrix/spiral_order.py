DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])
        total_nums = rows * cols

        res = []
        is_seen = [[False] * cols for _ in range(rows)]
        i = 0
        j = 0
        curr_dir_index = 0

        for _ in range(total_nums):
            res.append(matrix[i][j])
            is_seen[i][j] = True

            dx, dy = DIRECTIONS[curr_dir_index]
            next_i = i + dx
            next_j = j + dy

            if next_i >= rows or next_j >= cols or next_i < 0 or next_j < 0 or is_seen[next_i][next_j]:
                curr_dir_index = (curr_dir_index + 1) % 4
                dx, dy = DIRECTIONS[curr_dir_index]
                i = i + dx
                j = j + dy
            else:
                i = next_i
                j = next_j

        return res
