const array<array<int, 2>, 4> DIRECTIONS { array<int, 2>{0, 1}, {1, 0}, {-1, 0}, {0, -1} };

class Solution {
    inline queue<pair<size_t, size_t>> init_q(
        vector<vector<int>>& grid,
        const size_t rows,
        const size_t cols
    ) {
        queue<pair<size_t, size_t>> q;

        for (size_t i{ 0 }; i < rows; ++i) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if (cols > 1 && grid[i][cols - 1] == 1) {
                q.push({i, cols - 1});
                grid[i][cols - 1] = 0;
            }
        }

        for (size_t j{ 0 }; j < cols; ++j) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if (rows > 1 && grid[rows - 1][j] == 1) {
                q.push({rows - 1, j});
                grid[rows - 1][j] = 0;
            }
        }

        return q;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        auto q{ init_q(grid, rows, cols) };

        while (!q.empty()) {
            const auto [i, j] = q.front();
            q.pop();

            for (const auto [dx, dy] : DIRECTIONS) {
                const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
                const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

                if (new_i >= rows || new_j >= cols || grid[new_i][new_j] == 0) {
                    continue;
                }

                grid[new_i][new_j] = 0;
                q.push({new_i, new_j});
            }
        }

        int count{ 0 };

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
