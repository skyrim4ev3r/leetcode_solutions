class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max_sum{0};
        size_t rows{grid.size()};
        size_t cols{grid[0].size()};

        for (size_t i{0}; i < rows - 2; ++i) {
            for (size_t j{0}; j < cols - 2; ++j) {
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + 
                            grid[i + 1][j + 1] + 
                          grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                max_sum = max(sum, max_sum);
            }
        }

        return max_sum;
    }
};
