class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        res = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(1, cols):
                mat[i][j] += mat[i][j - 1]

        for j in range(cols):
            for i in range(1, rows):
                mat[i][j] += mat[i - 1][j]

        for i in range(rows):
            for j in range(cols):
                start_i = max(i, k) - k
                start_j = max(j, k) - k

                end_i = min(i + k, rows - 1)
                end_j = min(j + k, cols - 1)

                res[i][j] = mat[end_i][end_j]

                if start_j > 0:
                    res[i][j] -= mat[end_i][start_j - 1]

                if start_i > 0:
                    res[i][j] -= mat[start_i - 1][end_j]

                if start_i > 0 and start_j > 0:
                    res[i][j] += mat[start_i - 1][start_j - 1]

        return res
