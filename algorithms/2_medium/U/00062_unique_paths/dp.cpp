class Solution {
public:
    int uniquePaths(int m, int n) {
        const size_t rows = std::max(m, n);
        const size_t cols = std::min(n, m);
        auto dp = vector<int>(cols, 1);
        auto dp_next = vector<int>(cols, 0);

        for (size_t i = 1; i < rows; i += 1) {
            dp_next[0] = 1;
            for (size_t j = 1; j < cols; j += 1) {
                dp_next[j] = dp_next[j - 1] + dp[j];
            }
            std::swap(dp, dp_next);
        }

        return dp[cols - 1];
    }
};
