class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const size_t rows{matrix.size()};
        const size_t cols{matrix[0].size()};
        vector<vector<int>> res(cols, vector<int>(rows, 0));

        for (size_t j{0}; j < cols; ++j) {
            for (size_t i{0}; i < rows; ++i) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};
