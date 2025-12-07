class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, size_t rows, size_t cols, size_t i, size_t j) {
        if (i >= rows || j >= cols || grid[i][j] == 0) {
            return 0;
        }

        int sum{grid[i][j]};
        grid[i][j] = 0;

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            sum += dfs(grid, rows, cols, new_i, new_j);
        }

        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        int max{0};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] > 0) {
                    max = std::max(max, dfs(grid, rows, cols, i, j));
                }
            }
        }

        return max;
    }
};
