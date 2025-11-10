class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};

        if (rows == 1 && cols == 1) {
            return grid[0][0];
        }

        priority_queue<tuple<int, size_t, size_t>, vector<tuple<int, size_t, size_t>>, std::greater<tuple<int, size_t, size_t>>> min_heap;
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        const array<array<size_t, 2>, 2> directions{array<size_t, 2>{0,1}, {1,0}};
 
        min_heap.push({grid[0][0], 0, 0});
        is_visited[0][0] = true;

        while (!min_heap.empty()) {
            const auto [old_val, old_i, old_j] = min_heap.top();
            min_heap.pop();

            for (const auto &[dx, dy]: directions) {
                size_t new_i{old_i + dx};
                size_t new_j{old_j + dy};

                if (new_j >= cols || new_i >= rows || is_visited[new_i][new_j]) {
                    continue;
                }

                is_visited[new_i][new_j] = true;
                int new_val{grid[new_i][new_j] + old_val};

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return new_val;
                }

                min_heap.push({new_val, new_i, new_j});
            }
        }

        return -1;
    }
};
