class Solution {
    const array<tuple<int, int>, 8> DIRECTIONS = {tuple<int, int>{1, -1}, {1, 0}, {1, 1}, {0, 1},
                                                  {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         if (grid[0][0] == 1) {
            return -1;
        }

        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};

        if (rows == 1 && cols == 1) {
            return 1;
        }

        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        queue<tuple<size_t, size_t, int>> queue{};

        is_visited[0][0] = true;
        queue.push({0, 0, 1});

        while (!queue.empty()) {
            const auto [i, j, old_cost] = queue.front();
            queue.pop();

            for (auto const &[dx, dy]: DIRECTIONS) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                if (new_i >= rows || new_j >= cols) {
                    continue;
                }

                if (grid[new_i][new_j] == 1 || is_visited[new_i][new_j]) {
                    continue;
                }

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return old_cost + 1;
                }

                is_visited[new_i][new_j] = true;
                queue.push({new_i, new_j, old_cost + 1});
            }
        }

        return -1;
    }
};
