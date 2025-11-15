class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const size_t m{matrix.size()};
        const size_t n{matrix[0].size()};

        if (n <= 1 || m <= 1) {
            return true;
        }

        for (size_t i{0}; i < m - 1; ++i) {
            for (size_t j{0}; j < n - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
