class Solution {
public:
    static void setZeroes(vector<vector<int>>& matrix) {
        const size_t rows = matrix.size();
        const size_t cols = matrix[0].size();

        bool should_first_row_set_zero = false;
        bool should_first_col_set_zero = false;

        for (size_t i = 0; i < rows; i += 1) {
            if (matrix[i][0] == 0) {
                should_first_col_set_zero = true;
                break;
            }
        }

        for (size_t j = 0; j < cols; j += 1) {
            if (matrix[0][j] == 0) {
                should_first_row_set_zero = true;
                break;
            }
        }

        for (size_t i = 1; i < rows; i += 1) {
            for (size_t j = 1; j < cols; j += 1) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (size_t i = 1; i < rows; i += 1) {
            for (size_t j = 1; j < cols; j += 1) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (should_first_col_set_zero) {
            for (size_t i = 0; i < rows; i += 1) {
                matrix[i][0] = 0;
            }
        }

        if (should_first_row_set_zero) {
            for (size_t j = 0; j < cols; j += 1) {
                matrix[0][j] = 0;
            }
        }
    }
};
