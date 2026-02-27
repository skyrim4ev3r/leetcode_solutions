class Solution {
public:
    static int maximumAmount(const vector<vector<int>>& coins) {
        const size_t MAX_ROWS{ 500 };
        const size_t MAX_COLS{ 500 };
        const size_t MAX_SKIPS{ 3 };
        static array<array<array<int, MAX_SKIPS>, MAX_COLS + 1>, MAX_ROWS + 1> costs;
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);

        const size_t rows{ coins.size() };
        const size_t cols{ coins[0].size() };
        const size_t skips{ 3 };

        for (size_t i{ 0 }; i <= rows; ++i) {
            for (size_t j{ 0 }; j <= cols; ++j) {
                ranges::fill(costs[i][j].begin(), costs[i][j].begin() + skips, numeric_limits<int>::min());
            }
        }
        ranges::fill(costs[0][1].begin(), costs[0][1].begin() + skips, 0);

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                for(size_t k{ 0 }; k < skips; ++k) {
                    int curr_cost = coins[i][j] + std::max(costs[i][j + 1][k], costs[i + 1][j][k]);

                    if (k > 0) {
                        curr_cost = std::max(
                            curr_cost,
                            std::max(costs[i][j + 1][k - 1], costs[i + 1][j][k - 1])
                        );
                    }

                    costs[i + 1][j + 1][k] = curr_cost;
                }
            }
        }

        return *ranges::max_element(costs[rows][cols].begin(), costs[rows][cols].begin() + skips);
    }
};
