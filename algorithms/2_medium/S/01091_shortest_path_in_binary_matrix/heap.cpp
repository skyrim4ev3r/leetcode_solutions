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
        priority_queue<
            tuple<int, size_t, size_t>,
            vector<tuple<int, size_t, size_t>>,
            std::greater<tuple<int, size_t, size_t>>> heap{};

        is_visited[0][0] = true;
        heap.push({1, 0, 0});

        while (!heap.empty()) {
            const auto [old_cost, i, j] = heap.top();
            heap.pop();

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
                heap.push({old_cost + 1, new_i, new_j});
            }
        }

        return -1;
    }
};
