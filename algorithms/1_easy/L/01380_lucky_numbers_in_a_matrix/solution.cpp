class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        const size_t rows{matrix.size()};
        const size_t cols{matrix[0].size()};

        vector<int> rows_min_vals;
        rows_min_vals.reserve(rows);
        vector<int> cols_max_vals;
        cols_max_vals.reserve(cols);
        vector<int> res{};

        for (size_t j{0}; j < cols; ++j) {
            int max{INT_MIN};
            for (int i{0}; i < rows; ++i) {
                max = std::max(max, matrix[i][j]);
            }
            cols_max_vals.push_back(max);
        }

        for (size_t i{0}; i < rows; ++i) {
            int min{INT_MAX};
            for (int j{0}; j < cols; ++j) {
                min = std::min(min, matrix[i][j]);
            }
            rows_min_vals.push_back(min);
        }

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (matrix[i][j] == rows_min_vals[i] && matrix[i][j] == cols_max_vals[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};
