class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)

        if n == 1:
            return matrix[0][0]

        for i in range((n - 2), -1, -1):
            for j in range(n):
                min_next = matrix[i + 1][j]

                if j > 0:
                    min_next = min(min_next, matrix[i + 1][j - 1])

                if j + 1 < n:
                    min_next = min(min_next, matrix[i + 1][j + 1])

                matrix[i][j] += min_next

        return min(matrix[0])
