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
        vector<vector<int>> costs(rows, vector<int>(cols, numeric_limits<int>::max()));
        queue<tuple<size_t, size_t>> queue{};

        costs[0][0] = 1;
        queue.push({0, 0});

        while (!queue.empty()){
            const auto [i, j] = queue.front();
            queue.pop();
            int old_cost{costs[i][j]};

            for (auto const &[dx, dy]: DIRECTIONS) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                if (new_i >= rows || new_j >= cols) {
                    continue;
                }

                if (grid[new_i][new_j] == 1 || costs[new_i][new_j] <= old_cost + 1) {
                    continue;
                }

                costs[new_i][new_j] = old_cost + 1;

                queue.push({new_i, new_j});
            }
        }

        if (costs[rows - 1][cols - 1] == numeric_limits<int>::max()) {
            return -1;
        }

        return costs[rows - 1][cols - 1];
    }
};
