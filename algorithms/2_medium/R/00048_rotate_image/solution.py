class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        n_half = n // 2

        for i in range(n_half):
            start_j = i
            end_j = n - i - 1

            for j in range(start_j, end_j):
                temp = matrix[i][j]
                matrix[i][j] = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] =  matrix[n - 1 - i][n - 1 -j]
                matrix[n - 1 - i][n - 1 -j] =  matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = temp
