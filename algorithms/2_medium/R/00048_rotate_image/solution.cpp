class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const size_t n{matrix.size()};
        const size_t n_half{n / 2};

        for (size_t i{0}; i < n_half; ++i) {
            size_t start_j{i};
            size_t end_j{n - i - 1};

            for (size_t j{start_j}; j < end_j; ++j) {
                const int temp{matrix[i][j]};
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] =  matrix[n - 1 - i][n - 1 -j];
                matrix[n - 1 - i][n - 1 -j] =  matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
