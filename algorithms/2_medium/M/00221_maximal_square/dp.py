class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0])
        curr_row = [0] * (cols + 1)
        next_row = [0] * (cols + 1)
        max_side = 0

        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, -1, -1):
                if matrix[i][j] == '1':
                    curr_row[j] = 1 + min(next_row[j + 1], next_row[j], curr_row[j + 1])
                    max_side = max(max_side, curr_row[j])

            next_row = curr_row
            curr_row = [0] * (cols + 1)

        return pow(max_side, 2)
