class Solution {
public:
    int uniquePaths(int m, int n) {
        const size_t rows{static_cast<size_t>(m)};
        const size_t cols{static_cast<size_t>(n)};

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1;

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }

                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
