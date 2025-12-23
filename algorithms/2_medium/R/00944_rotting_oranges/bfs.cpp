class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        queue<array<size_t, 2>> q{};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int count{0};

        while (!q.empty()) {
            const size_t len{q.size()};

            for (size_t k{0}; k < len; ++k) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto& [dx, dy] : DIRECTIONS) {
                    const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                    const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                    if (new_i >= rows || new_j >= cols || grid[new_i][new_j] != 1) {
                        continue;
                    }

                    grid[new_i][new_j] = 2;
                    q.push({new_i, new_j});
                }
            }

            if (!q.empty()) {
                count += 1;
            }
        }

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return count;
    }
};
