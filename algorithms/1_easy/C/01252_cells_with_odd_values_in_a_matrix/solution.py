class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row_vals = [0] * m
        col_vals = [0] * n

        for index in indices:
            row_vals[index[0]] += 1
            col_vals[index[1] ] += 1

        count = 0

        for row_val in row_vals:
            for col_val in col_vals:
                if ((row_val + col_val) & 1) == 1:
                    count += 1

        return count
