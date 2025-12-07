class Solution {
public:
    static int uniquePathsWithObstacles(const vector<vector<int>>& obstacle_grid) {
        const size_t rows{obstacle_grid.size()};
        const size_t cols{obstacle_grid[0].size()};

        if (obstacle_grid[0][0] == 1 || obstacle_grid[rows - 1][cols - 1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = 1;

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (obstacle_grid[i][j] == 0) {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }

                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
