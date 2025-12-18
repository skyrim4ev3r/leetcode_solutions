class Solution {
    struct Cell {
        int cost;
        size_t i;
        size_t j;
        bool operator<(const Cell& other) const {
            return cost > other.cost;
        }
     };
public:
    int minimumTime(vector<vector<int>>& grid) {
        const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<Cell> heap{};
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        heap.push({0, 0, 0});
        is_visited[0][0] = true;

        while (!heap.empty()) {
            const auto [old_cost, old_i, old_j] = heap.top();
            heap.pop();

            for (const auto& [dx, dy] : DIRECTIONS) {
                size_t new_i{static_cast<size_t>(static_cast<int>(old_i) + dx)};
                size_t new_j{static_cast<size_t>(static_cast<int>(old_j) + dy)};

                if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j]) {
                    continue;
                }

                const int grid_val{grid[new_i][new_j]};
                const int new_cost{old_cost + 1 >= grid_val ? old_cost + 1 : grid_val + ((grid_val - (old_cost + 1)) & 1)};

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return new_cost;
                }

                is_visited[new_i][new_j] = true;
                heap.push({new_cost, new_i, new_j});
            }
        }

        return -1;
    }
};
