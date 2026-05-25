class Solution {
public:
    static int minPathSum(const vector<vector<int>>& grid) {
        const size_t rows = grid.size();
        const size_t cols = grid[0].size();
        auto dp = vector<int>(cols);
        auto dp_next = vector<int>(cols);
        dp[0] = grid[0][0];
        for  (size_t j = 1; j < cols; j += 1) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for  (size_t i = 1; i < rows; i += 1) {
            dp_next[0] = dp[0] + grid[i][0];
            for  (size_t j = 1; j < cols; j += 1) {
                const int from_top = dp[j];
                const int from_left = dp_next[j - 1];
                const int min = std::min(from_left, from_top);
                dp_next[j] = min + grid[i][j];
            }
            std::swap(dp, dp_next);
        }

        return dp[cols - 1];
    }
};
