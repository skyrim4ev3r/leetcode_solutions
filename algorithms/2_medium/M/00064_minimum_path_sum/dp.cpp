class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        
        for (size_t i{1}; i < rows; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (size_t j{1}; j < cols; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (size_t i{1}; i < rows; ++i) {
            for (size_t j{1}; j < cols; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[rows - 1][ cols - 1];
    }
};
