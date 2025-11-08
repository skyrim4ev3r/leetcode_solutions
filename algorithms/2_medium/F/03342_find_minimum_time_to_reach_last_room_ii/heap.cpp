class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minTimeToReach(vector<vector<int>>& move_time) {
        const size_t rows{move_time.size()};
        const size_t cols{move_time[0].size()};

        priority_queue<tuple<int, size_t, size_t, bool>> heap{};
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        heap.push({0, 0, 0, true});
        is_visited[0][0] = true;

        while (!heap.empty()) {
            const auto [cost, i, j, flip_flop] = heap.top();
            heap.pop();

            for (const auto &[dx, dy]: DIRECTIONS) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;
                const int new_cost = min(cost, -move_time[new_i][new_j]) - (flip_flop ? 1 : 2);

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return abs(new_cost);
                }

                heap.push({new_cost, new_i, new_j, !flip_flop});
            }
        }

        return -1;
    }
};
