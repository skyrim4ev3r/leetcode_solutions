const size_t MAX_ROWS{ 200 };
const size_t MAX_COLS{ 200 };
const size_t MAX_K{ 1'000 };

class Solution {
public:
    static int maxPathScore(const vector<vector<int>>& grid, const int k) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        const size_t k_usize{ static_cast<size_t>(k) };
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
        static array<array<array<int, MAX_K + 1>, MAX_COLS>, MAX_ROWS> dp;

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                for (size_t c{ 0 }; c <= k_usize; ++c) {
                    dp[i][j][c] = -1;
                }
            }
        }

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

        return *std::max_element(dp[rows - 1][cols - 1].cbegin(), dp[rows - 1][cols - 1].cbegin() + k_usize + 1);
    }
};
