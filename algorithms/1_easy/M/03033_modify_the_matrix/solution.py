class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        rows = len(matrix)
        cols = len(matrix[0])
        result = [[0] * cols for _ in range(rows)]

        for j in range(cols):
            max_val = -sys.maxsize - 1

            for i in range(rows):
                max_val = max(max_val, matrix[i][j])

            for i in range(rows):
                if matrix[i][j] == -1:
                    result[i][j] = max_val
                else:
                    result[i][j] = matrix[i][j]

        return result
