class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        count_negative = 0
        res = 0
        min_abs_val = sys.maxsize

        for row in matrix:
            for cell in row:
                if cell < 0:
                    count_negative += 1

                min_abs_val = min(min_abs_val, abs(cell))
                res += abs(cell)

        if (count_negative & 1) == 1:
            # Adjust the total sum if there are an odd number of negative values.
            # If there is at least one zero in the matrix, then `min_abs_val` will be zero,
            # and subtracting twice `min_abs_val` will have no effect on the sum, 
            # effectively covering that edge case as well.
            res -= (2 * min_abs_val)

        return res
