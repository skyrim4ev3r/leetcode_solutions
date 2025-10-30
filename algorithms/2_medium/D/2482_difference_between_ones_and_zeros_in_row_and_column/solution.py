class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        rows = len(grid)
        cols = len(grid[0])

        #
        #   diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
        #              = onesRowi + onesColj - (len_row - onesRowi) - (len_cols - onesColj)
        #              = onesRowi + onesColj - len_row + onesRowi - len_cols + onesColj
        #
        #              = 2 * onesRowi + 2 * onesColj - (len_cols + len_row)
        #

        ones_rows_mul_by_2 = [0] * rows
        ones_cols_mul_by_2 = [0] * cols

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    ones_rows_mul_by_2[i] += 2 # Increment by 2 to use it instead of => 2 * onesRowi 
                    ones_cols_mul_by_2[j] += 2 # Increment by 2 to use it instead of => 2 * ones_cols 

        for i in range(rows):
            for j in range(cols):
                #            2 * onesRowi           + 2 * onesColj      - (len_cols + len_row)
                grid[i][j] = ones_rows_mul_by_2[i] + ones_cols_mul_by_2[j] - (rows + cols)

        return grid
