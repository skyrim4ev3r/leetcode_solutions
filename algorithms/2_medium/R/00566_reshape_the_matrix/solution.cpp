class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int target_rows_i32, int target_cols_i32) {
        const size_t original_rows{mat.size()};
        const size_t original_cols{mat[0].size()};
        const size_t target_rows{static_cast<size_t>(target_rows_i32)};
        const size_t target_cols{static_cast<size_t>(target_cols_i32)};

        if ((original_rows * original_cols != target_rows * target_cols)
            || (original_rows == target_rows && original_cols == target_cols))
        {
            return mat;
        }

        vector<vector<int>> res(target_rows, vector<int>(target_cols, 0));

        vector<int> tmp{};

        for (size_t i{target_rows - 1}; i < target_rows; --i) {
            for (size_t j{target_cols - 1}; j < target_cols; --j) {
                if (tmp.empty()) {
                    tmp = mat.back();
                    mat.pop_back();
                }

                res[i][j] = tmp.back();
                tmp.pop_back();
            }
        }

        return res;
    }
};
