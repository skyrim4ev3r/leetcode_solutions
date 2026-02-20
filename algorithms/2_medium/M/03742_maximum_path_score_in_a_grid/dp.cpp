class Solution {
public:
    static int maxPathScore(const vector<vector<int>>& grid, const int k) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        const size_t k_usize{ static_cast<size_t>(k) };
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k_usize + 1, -1)));
        dp[0][0][0] = 0;

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                const int score_cell{ grid[i][j] };
                const int cost_cell{ score_cell != 0 ? 1 : 0 };

                if (i > 0) {
                    for (size_t c{ 0 }; c <= k_usize; ++c) {
                        if (dp[i - 1][j][c] != -1) {
                            if (c + cost_cell <= k_usize) {
                                dp[i][j][c + cost_cell] = std::max(dp[i][j][c + cost_cell], dp[i - 1][j][c] + score_cell);
                            }
                        }
                    }
                }

                if (j > 0) {
                    for (size_t c{ 0 }; c <= k_usize; ++c) {
                        if (dp[i][j - 1][c] != -1) {
                            if (c + cost_cell <= k_usize) {
                                dp[i][j][c + cost_cell] = std::max(dp[i][j][c + cost_cell], dp[i][j - 1][c] + score_cell);
                            }
                        }
                    }
                }
            }
        }

        return *ranges::max_element(dp[rows - 1][cols - 1]);
    }
};
