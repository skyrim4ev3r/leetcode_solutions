class Solution {
public:
    static int uniquePaths(vector<vector<int>>& grid) {
        const int MOD_TO{1'000'000'007};
        const size_t m{grid.size()};
        const size_t n{grid[0].size()};
        vector<vector<array<int, 2>>> dp(m, vector<array<int, 2>>(n, array<int, 2>{0, 0}));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (size_t i{1}; i < m; ++i) {
            if (grid[i - 1][0] == 1) {
                break;
            }

            dp[i][0][1] = 1;
        }

        for (size_t j{1}; j < n; ++j) {
            if (grid[0][j - 1] == 1) {
                break;
            }

            dp[0][j][0] = 1;
        }

        for (size_t i{1}; i < m; ++i) {
            for (size_t j{1}; j < n; ++j) {
                if (grid[i - 1][j] == 0) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD_TO;
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % MOD_TO;
                } else {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0]) % MOD_TO;
                }

                if (grid[i][j - 1] == 0) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][0]) % MOD_TO;
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][1]) % MOD_TO;
                } else {
                    dp[i][j][0] = (dp[i][j][0] + dp[i][j - 1][1]) % MOD_TO;
                }
            }
        }

        return (dp[m - 1][n - 1][0] +  dp[m - 1][n - 1][1]) % MOD_TO;
    }
};
