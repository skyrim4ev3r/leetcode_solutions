class Solution {
private:
    const vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    long dfs_iterative(vector<vector<int>> &grid, size_t i, size_t j, size_t rows, size_t cols) {

        long sum{static_cast<long>(grid[i][j])};
        stack<pair<size_t, size_t>> stack{};
        stack.push({i, j});
        grid[i][j] = 0;

        while (!stack.empty()) {
            auto [old_i, old_j] = stack.top();
            stack.pop();

            for (const auto &[dx, dy]: directions) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(old_i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(old_j) + dy)};

                if (new_i >=  rows || new_j >= cols || grid[new_i][new_j] == 0) { 
                    continue;
                }

                sum += static_cast<long>(grid[new_i][new_j]);
                grid[new_i][new_j] = 0;
                stack.push({new_i, new_j});
            }
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
                    long sum = dfs_iterative(grid, i, j, rows, cols);

                    if (sum % k_i64 == 0) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
