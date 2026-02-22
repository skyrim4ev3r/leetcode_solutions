class Solution {
public:
    static vector<vector<int>> modifiedMatrix(const vector<vector<int>>& matrix) {
        const size_t rows{ matrix.size() };
        const size_t cols{ matrix[0].size() };
        auto result{ matrix };

        for (size_t j{ 0 }; j < cols; ++j) {
            int max{ numeric_limits<int>::min() };

            for (size_t i{ 0 }; i < rows; ++i) {
                max = std::max(max, matrix[i][j]);
            }

            for (size_t i{ 0 }; i < rows; ++i) {
                if (matrix[i][j] == -1) {
                    result[i][j] = max;
                }
            }
        }

        return result;
    }
};
