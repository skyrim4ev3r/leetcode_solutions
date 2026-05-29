class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        n = len(matrix)
        res = [0] * n

        for i in range(n):
            res[i] = sum(matrix[i])

        return res
