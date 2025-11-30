class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        res = []
        n = len(matrix)
        m = len(matrix[0])

        for j in range(m):
            res.append([])
            for i in range(n):
                res[-1].append(matrix[i][j])

        return res
