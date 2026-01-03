class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        const size_t rows {grid.size()};
        const size_t cols {grid[0].size()};

        for (size_t j {0}; j < cols; ++j) {
            for (size_t i {0}; i < rows; ++i) {
                if ((i > 0 && grid[i][j] != grid[i - 1][j]) || (j > 0 && grid[i][j] == grid[i][j - 1])) {
                    return false;
                }
            }
        }

        return true;
    }
};
