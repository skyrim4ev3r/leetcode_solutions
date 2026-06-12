// (MAX_ACCEPTED_COLS + 1) * (MAX_ACCEPTED_COLS + 1) should be fit in ptrdiff_t
constexpr ptrdiff_t max_accepted_rows = 200;
constexpr ptrdiff_t max_accepted_cols = 200;

class NumMatrix {
    vector<int> prefix;
    ptrdiff_t rows;
    ptrdiff_t cols;
public:
    NumMatrix(const vector<vector<int>>& matrix) {
        assert(std::ssize(matrix) > 0 && std::ssize(matrix[0]) > 0 &&
           std::ssize(matrix) <= max_accepted_rows && std::ssize(matrix[0]) <= max_accepted_cols);
        const ptrdiff_t rows = std::ssize(matrix) + 1;
        const ptrdiff_t cols = std::ssize(matrix[0]) + 1;
        prefix = vector<int>(rows * cols, 0);

        for (ptrdiff_t i = 1; i < rows; i += 1) {
            assert(matrix[i - 1].size() + 1 == cols);
            for (ptrdiff_t j = 1; j < cols; j += 1) {
                const ptrdiff_t prefix_idx = (i * cols + j);
                const ptrdiff_t prefix_idx_up = (i - 1) * cols + j;
                const ptrdiff_t prefix_idx_left = i * cols + j - 1;
                const ptrdiff_t prefix_idx_upleft = (i - 1) * cols + j - 1;

                prefix[prefix_idx] = matrix[i - 1][j - 1] + 
                                    prefix[prefix_idx_up] +
                                    prefix[prefix_idx_left] -
                                    prefix[prefix_idx_upleft];
            }
        }

        this->rows = rows;
        this->cols = cols;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        assert(row1 >= 0 && col1 >= 0 && row2 >=0 && col2 >= 0 &&
            row1 <= row2 && col1 <= col2 &&
            row2 < rows - 1 && col2 < cols - 1);

        const ptrdiff_t upleft = row1 * cols + col1;
        const ptrdiff_t up = row1 * cols + (col2 + 1);
        const ptrdiff_t left = (row2 + 1) * cols + col1;
        const ptrdiff_t downright = (row2 + 1) * cols + (col2 + 1);

        return prefix[downright] +
               prefix[upleft] -
               prefix[up] -
               prefix[left];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
