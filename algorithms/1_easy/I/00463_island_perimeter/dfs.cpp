class Solution {
    array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(
        vector<vector<int>>&  grid,
        const size_t rows,
        const size_t cols,
        const size_t i,
        const size_t j
    ) {
        if (i >= rows || j >= cols || grid[i][j] == 0) {
            return 1;
        }

        if (grid[i][j] == -1) {
            return 0;
        }

        grid[i][j] = -1;
        int curr_perimeter{0};

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};
            curr_perimeter += dfs(grid, rows, cols, new_i, new_j);
        }

        return curr_perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, rows, cols, i, j);
                }
            }
        }

        return 0;
    }
};
