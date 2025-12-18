class Solution {
    struct Cell {
        int cost;
        size_t i;
        size_t j;

        bool operator<(const Cell& other) const {
            return cost > other.cost; // Reverse for min-heap
        }
    };
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        priority_queue<Cell> heap;
        heap.push({grid[0][0], 0, 0});
        is_visited[0][0] = true;
        array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!heap.empty()) {
            auto [old_cost, i, j] = heap.top();
            heap.pop();

            for (const auto& [dx, dy] : DIRECTIONS) {
                const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j]) {
                    continue;
                }

                const int new_cost{old_cost + grid[new_i][new_j]};

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
