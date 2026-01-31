const array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {0, -1}, {-1, 0} };

class Solution {
    static void dfs_calc_first_island(
        vector<vector<int>>& grid,
        size_t rows,
        size_t cols,
        size_t i,
        size_t j,
        queue<pair<size_t, size_t>>& q
    ) {
        if (i >= rows || j >= cols || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = -1;
        q.push({i, j});

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
            const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

            dfs_calc_first_island(grid, rows, cols, new_i, new_j, q);
        }
    }

    static inline queue<pair<size_t, size_t>> calc_first_island(
        vector<vector<int>>& grid,
        const size_t& rows,
        const size_t& cols
    ) {
        queue<pair<size_t, size_t>> q{};

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    dfs_calc_first_island(grid, rows, cols, i, j, q);
                    return q;
                }
            }
        }

        return q;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        auto q = calc_first_island(grid, rows, cols);
        int level{ 0 };

        while (!q.empty()) {
            const size_t curr_len{ q.size() };

            for (size_t c{ 0 }; c < curr_len; ++c) {  
                auto [i, j] = q.front();
                q.pop();

                for (const auto& [dx, dy] : DIRECTIONS) {
                    const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
                    const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

                    if (new_i >= rows || new_j >= cols || grid[new_i][new_j] == -1) {
                        continue;
                    }

                    if (grid[new_i][new_j] == 1) {
                        return level;
                    }

                    grid[new_i][new_j] = -1;
                    q.push({new_i, new_j});
                }
            }

            level += 1;
        }

        return -1;
    }
};
