INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize - 1

class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        rows = len(matrix)
        cols = len(matrix[0])

        rows_min_vals = []
        cols_max_vals = []
        res = []

        for j in range(cols):
            max_val = INT_MIN
            for i in range(rows):
                max_val = max(max_val, matrix[i][j])
            cols_max_vals.append(max_val)

        for i in range(rows):
            min_val = INT_MAX
            for j in range(cols):
                min_val = min(min_val, matrix[i][j])
            rows_min_vals.append(min_val)

        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == rows_min_vals[i] and matrix[i][j] == cols_max_vals[j]:
                    res.append(matrix[i][j])

        return res
