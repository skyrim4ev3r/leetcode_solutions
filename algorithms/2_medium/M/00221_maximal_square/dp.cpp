class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const size_t rows{ matrix.size() };
        const size_t cols{ matrix[0].size() };
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int max_side{ 0 };

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = 1 + std::min(dp[i][j], std::min(dp[i + 1][j], dp[i][j + 1]));
                    max_side = std::max(max_side, dp[i + 1][j + 1]);
                }
            }
        }

        return std::pow(max_side, 2);
    }
};
