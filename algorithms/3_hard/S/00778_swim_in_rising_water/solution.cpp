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
    int swimInWater(vector<vector<int>>& grid) {
        size_t n{grid.size()};

        if (n <= 1) {
            return 0;
        }

        auto is_visited{vector<vector<bool>>(n, vector<bool>(n, false))};

        int directions[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<Cell> heap{};

        heap.push(Cell{grid[0][0], 0, 0});
        is_visited[0][0] = true;

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            for (size_t directions_index{0}; directions_index < 4; ++directions_index) {
                size_t new_i = static_cast<size_t>(static_cast<int>(cell.i) + directions[directions_index][0]);
                size_t new_j = static_cast<size_t>(static_cast<int>(cell.j) + directions[directions_index][1]);

                if (new_i >= n || new_j >= n || is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                int new_cost = std::max(grid[new_i][new_j], cell.cost);

                if (new_i == n - 1 && new_j == n - 1) {
                    return new_cost;
                }

                heap.push(Cell{new_cost, new_i, new_j});
            }
        }

        return -1;
    }
};
