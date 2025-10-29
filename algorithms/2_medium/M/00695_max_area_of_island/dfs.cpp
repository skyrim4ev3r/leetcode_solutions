class Solution {
    const vector<pair<int,int>> directions{{1, 0},{0, 1},{-1, 0},{0, -1}};

    void dfs(vector<vector<int>>& grid, size_t i, size_t j, int &count) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }

        count += 1;
        grid[i][j] = 0;

        for(const auto &dir: directions) {
            const size_t new_i = static_cast<size_t>(static_cast<int>(i) + dir.first);
            const size_t new_j = static_cast<size_t>(static_cast<int>(j) + dir.second);
            dfs(grid, new_i, new_j, count);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max{0};
        size_t rows{grid.size()};
        size_t cols{grid[0].size()};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    int count{0};
                    dfs(grid, i, j, count);
                    max = std::max(max, count);
                }
            }
        }

        return max;
    }
};
