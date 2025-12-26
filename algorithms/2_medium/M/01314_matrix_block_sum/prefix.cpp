class Solution {
public:
    static vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        const size_t rows {mat.size()};
        const size_t cols {mat[0].size()};
        const size_t k_usize {static_cast<size_t>(k)};
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{1}; j < cols; ++j) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (size_t j{0}; j < cols; ++j) {
            for (size_t i{1}; i < rows; ++i) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                const size_t start_i = std::max(i, k_usize) - k_usize;
                const size_t start_j = std::max(j, k_usize) - k_usize;

                const size_t end_i = std::min(i + k_usize, rows - 1);
                const size_t end_j = std::min(j + k_usize, cols - 1);

                res[i][j] = mat[end_i][end_j];

                if (start_j > 0) {
                    res[i][j] -= mat[end_i][start_j - 1];
                }

                if (start_i > 0) {
                    res[i][j] -= mat[start_i - 1][end_j];
                }

                if (start_i > 0 && start_j > 0) {
                    res[i][j] += mat[start_i - 1][start_j - 1];
                }
            }
        }

        return res;
    }
};
