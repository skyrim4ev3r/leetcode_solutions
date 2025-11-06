class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int, size_t, size_t>> cost_queue{};
        const size_t rows{maze.size()};
        const size_t cols{maze[0].size()};
        const size_t start_i{static_cast<size_t>(entrance[0])};
        const size_t start_j{static_cast<size_t>(entrance[1])};
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));

        cost_queue.push({0, start_i, start_j});
        is_visited[start_i][start_j] = true;

        while (!cost_queue.empty()) {
            const auto [curr_cost, curr_i, curr_j] = cost_queue.front();
            cost_queue.pop();
            int new_cost{curr_cost + 1};
            for (const auto &[dx, dy]: DIRECTIONS) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(curr_i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(curr_j) + dy)};

                if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j] || maze[new_i][new_j] == '+') {
                    continue;
                }

                if (new_i == rows - 1 || new_j == cols - 1 || new_i == 0 || new_j == 0) {
                    return new_cost;
                }

                is_visited[new_i][new_j] = true;
                cost_queue.push({new_cost, new_i, new_j});
            }
        }

        return -1;
    }
};
