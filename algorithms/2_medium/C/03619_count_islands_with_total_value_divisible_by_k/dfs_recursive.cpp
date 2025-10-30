class Solution {
private:
    const vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    long dfs(vector<vector<int>> &grid, size_t i, size_t j, size_t rows, size_t cols) {

        if (i >= rows || j >= cols || grid[i][j] == 0) {
            return 0;
        }

        long sum{static_cast<long>(grid[i][j])};
        grid[i][j] = 0;

        for (const auto &[dx, dy]: directions) {
            size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};
            sum += dfs(grid, new_i, new_j, rows, cols);
        }

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count{0};
        size_t rows{grid.size()};
        size_t cols{grid[0].size()};
        long k_i64{static_cast<long>(k)};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    long sum = dfs(grid, i, j, rows, cols);

                    if (sum % k_i64 == 0) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
