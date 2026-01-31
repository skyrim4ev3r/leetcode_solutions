class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const size_t n{ matrix.size() };

        if (n == 1) {
            return matrix[0][0];
        }

        for (size_t i{ n - 2 }; i < n; --i) {
            for (size_t j{ 0 }; j < n; ++j) {
                int min { matrix[i + 1][j] };

                if (j > 0) {
                    min = std::min(min, matrix[i + 1][j - 1]);
                }

                if (j + 1 < n) {
                    min = std::min(min, matrix[i + 1][j + 1]);
                }

                matrix[i][j] += min;
            }
        }

        return *min_element(matrix[0].cbegin(), matrix[0].cend());
    }
};
