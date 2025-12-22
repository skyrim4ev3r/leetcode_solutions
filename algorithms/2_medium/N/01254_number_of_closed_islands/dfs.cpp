class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{0, 1}, {0, -1},{1, 0}, {-1, 0}};

    void dfs(
        const vector<vector<int>>& grid,
        vector<vector<bool>>& is_visited,
        const size_t rows,
        const size_t cols,
        const size_t i,
        const size_t j
    ) {
        if (i >= rows || j >= cols || grid[i][j] == 1 || is_visited[i][j]) {
            return;
        }

        is_visited[i][j] = true;

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            dfs(grid, is_visited, rows, cols, new_i, new_j);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        int count{0};

        for (size_t i{0}; i < rows; ++i) {
            if (grid[i][0] == 0 && is_visited[i][0] == false) {
                dfs(grid, is_visited, rows, cols, i, 0);
            }

            if (grid[i][cols - 1] == 0 && is_visited[i][cols - 1] == false) {
                dfs(grid, is_visited, rows, cols, i, cols - 1);
            }
        }

        for (size_t j{0}; j < cols; ++j) {
            if (grid[0][j] == 0 && is_visited[0][j] == false) {
                dfs(grid, is_visited, rows, cols, 0, j);
            }

            if (grid[rows - 1][j] == 0 && is_visited[rows - 1][j] == false) {
                dfs(grid, is_visited, rows, cols, rows - 1, j);
            }
        }

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 0 && is_visited[i][j] == false) {
                    count += 1;
                    dfs(grid, is_visited, rows, cols, i, j);
                }
            }
        }

        return count;
    }
};
