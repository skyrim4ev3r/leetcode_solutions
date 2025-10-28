class Solution {

    const vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>> &grid, const int target_path_len, int curr_path_len, int &count, size_t i, size_t j) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) {
            return;
        }

        if (grid[i][j] == 2) {
            if (target_path_len == curr_path_len) {
                count += 1;
            }

            return;
        }

        grid[i][j] = -1;
        for (auto &direction: directions) {
            size_t new_i = static_cast<size_t>(static_cast<int>(i) + direction[0]);
            size_t new_j = static_cast<size_t>(static_cast<int>(j) + direction[1]);
            dfs(grid, target_path_len, curr_path_len + 1, count, new_i, new_j);
        }
        grid[i][j] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        size_t i_start{0};
        size_t j_start{0};
        int target_path_len{0};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 0 || grid[i][j] == 2) {
                    target_path_len += 1;
                }

                if (grid[i][j] == 1) {
                    i_start = i;
                    j_start = j;
                }
            }
        }

        int count{0};
        dfs(grid, target_path_len, 0, count, i_start, j_start);

        return count;
    }
};
