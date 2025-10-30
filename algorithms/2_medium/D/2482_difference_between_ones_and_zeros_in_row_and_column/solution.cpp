class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        size_t rows{grid.size()};
        size_t cols{grid[0].size()};

        /*
            diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
                       = onesRowi + onesColj - (len_row - onesRowi) - (len_cols - onesColj)
                       = onesRowi + onesColj - len_row + onesRowi - len_cols + onesColj

                       = 2 * onesRowi + 2 * onesColj - (len_cols + len_row)
        */

        vector<int> ones_rows_mul_by_2(rows, 0);
        vector<int> ones_cols_mul_by_2(cols, 0);

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ones_rows_mul_by_2[i] += 2; // Increment by 2 to use it instead of => 2 * onesRowi 
                    ones_cols_mul_by_2[j] += 2; // Increment by 2 to use it instead of => 2 * ones_cols 
                }
            }
        }

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                // 2 * onesRowi + 2 * onesColj - (len_cols + len_row)
                grid[i][j] = ones_rows_mul_by_2[i] + ones_cols_mul_by_2[j] - (rows + cols);
            }
        }

        return grid;
    }
};
