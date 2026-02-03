const array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
    bool dfs(
        const vector<vector<char>>& grid,
        vector<vector<bool>>& visited,
        const char parent_char,
        const size_t i,
        const size_t j,
        const size_t rows,
        const size_t cols,
        bool& has_cycle
    ) {
        if (has_cycle || i >= rows || j >= cols || grid[i][j] != parent_char) {
            return false;
        }

        if (visited[i][j]) {
            return true;
        }

        visited[i][j] = true;
        int count{ 0 };

        for (const auto& [dx, dy] : DIRECTIONS) {
            const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
            const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

            if (dfs(grid, visited, parent_char, new_i, new_j, rows, cols, has_cycle)) {
                count += 1;
            }

            if (count >= 2) {
                has_cycle = true;
                return false;
            }
        }

        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool has_cycle{ false };

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                if (!visited[i][j]) {
                    const char parent_char{ grid[i][j] };

                    dfs(grid, visited, parent_char, i, j, rows, cols, has_cycle);

                    if (has_cycle) {
                        return true;
                    }
                }

            }
        }

        return false;
    }
};
