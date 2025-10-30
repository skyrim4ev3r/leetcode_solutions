class Solution {
    struct Cell {
        int cost;
        size_t i;
        size_t j;

        bool operator<(const Cell& other) const {
            return cost > other.cost; // Reverse for min-heap
        }

        bool operator==(const Cell& other) const {
            return (i == other.i) && (j == other.j);
        }
    };
public:
    int minCost(vector<vector<int>>& grid) {
        size_t rows{grid.size()};
        size_t cols{grid[0].size()};

        const vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        size_t directions_len{directions.size()};
        vector<vector<int>> cost_matrix{vector<vector<int>>(rows, vector<int>(cols, INT_MAX))};
        priority_queue<Cell> heap{};

        heap.push(Cell {0, 0, 0});
        cost_matrix[0][0] = 0;

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            if (cell.i == rows - 1 && cell.j == cols - 1) {
                return cell.cost;
            }

            for (size_t index{0}; index < directions_len; ++index) {
                size_t new_i{static_cast<size_t>(static_cast<int>(cell.i) + directions[index].first)};
                size_t new_j{static_cast<size_t>(static_cast<int>(cell.j) + directions[index].second)};

                if (new_i >= rows || new_j >= cols) {
                    continue;
                }

                int new_cost{0};

                if (index == static_cast<size_t>(grid[cell.i][cell.j] - 1)) {
                    new_cost = cell.cost;
                } else {
                    new_cost = cell.cost + 1;
                }

                if (new_cost < cost_matrix[new_i][new_j]) {
                    cost_matrix[new_i][new_j] = new_cost;
                    heap.push(Cell { new_cost, new_i, new_j });
                }

            }
        }

        return -1;
    }
};
