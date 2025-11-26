const int MOD_TO{1'000'000'007};

class Solution {
public:
    static int numberOfPaths(vector<vector<int>>& grid, int k) {
        const size_t m{grid.size()};
        const size_t n{grid[0].size()};
        const size_t k_usize{static_cast<size_t>(k)};
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k_usize, 0)));

        dp[0][0][static_cast<size_t>(grid[0][0] % k)] = 1;

        for (size_t i{1}; i < m; ++i) {
            int val{grid[i][0]};

            for (int t{0}; t < k; ++t) {
                dp[i][0][static_cast<size_t>((t + val) % k)] = dp[i - 1][0][static_cast<size_t>(t)];
            }
        }

        for (size_t j{1}; j < n; ++j) {
            int val{grid[0][j]};

            for (int t{0}; t < k; ++t) {
                dp[0][j][static_cast<size_t>((t + val) % k)] = dp[0][j - 1][static_cast<size_t>(t)];
            }
        }

        for (size_t i{1}; i < m; ++i) {
            for (size_t j{1}; j < n; ++j) {
                int val{grid[i][j]};

                for (int t{0}; t < k; ++t) {
                    dp[i][j][static_cast<size_t>((t + val) % k)] = (dp[i][j - 1][static_cast<size_t>(t)] + 
                                                                    dp[i - 1][j][static_cast<size_t>(t)]) % MOD_TO;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
