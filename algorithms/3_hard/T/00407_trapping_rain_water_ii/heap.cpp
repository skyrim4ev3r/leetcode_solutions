class Solution {
    struct Cell {
        int height;
        size_t i;
        size_t j;

        bool operator<(const Cell& other) const {
            return height > other.height;
        }
    };

public:
    int trapRainWater(vector<vector<int>>& height_map) {
        size_t m{height_map.size()};
        size_t n{height_map[0].size()};

        priority_queue<Cell> heap;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));

        for (size_t i{0}; i < m; ++i) {
            for (size_t j{0}; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    is_visited[i][j] = true;
                    heap.push(Cell{height_map[i][j], i, j});
                }
            }
        }

        int sum{0};
        int directions[4][2]{{-1, 0}, {0, -1}, {1,0}, {0,1}};

        while (!heap.empty()) {
            Cell cell = heap.top();
            heap.pop();

            size_t old_j{cell.j};
            size_t old_i{cell.i};
            int old_height{cell.height};

            for (size_t dir_index{0}; dir_index < 4; ++dir_index) {
                size_t new_i = static_cast<size_t>(static_cast<int>(old_i) + directions[dir_index][0]);
                size_t new_j = static_cast<size_t>(static_cast<int>(old_j) + directions[dir_index][1]);

                if (new_i >= m || new_j >= n || is_visited[new_i][new_j]) {
                    continue;
                }

                int new_height{height_map[new_i][new_j]};
                sum += std::max(0, old_height - new_height);
                is_visited[new_i][new_j] = true;
                heap.push(Cell{std::max(new_height, old_height), new_i, new_j});
            }
        }

        return sum;
    }
};
