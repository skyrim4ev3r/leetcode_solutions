class Solution:
    def matrixReshape(self, mat: List[List[int]], target_rows: int, target_cols: int) -> List[List[int]]:
        original_rows = len(mat)
        original_cols = len(mat[0])

        if (original_rows * original_cols != target_rows * target_cols) \
            or (original_rows == target_rows and original_cols == target_cols):

            return mat

        res = [[0] * target_cols for _ in range(target_rows)]

        tmp = []

        for i in range(target_rows - 1, -1, -1):
            for j in range(target_cols - 1, -1, -1):
                if not tmp:
                    tmp = mat.pop()

                res[i][j] = tmp.pop()

        return res
