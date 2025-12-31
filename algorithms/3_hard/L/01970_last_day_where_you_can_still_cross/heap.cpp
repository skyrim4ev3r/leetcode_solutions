const array<array<int, 2>, 4> DIRECTIONS = {array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    static int latestDayToCross(int row, int col, const vector<vector<int>>& cells) {
        const size_t rows {static_cast<size_t>(row)};
        const size_t cols {static_cast<size_t>(col)};
        vector<vector<int>> mat(rows, vector<int>(cols, numeric_limits<int>::max()));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<tuple<int, size_t, size_t>> heap {};

        for (int i {1}; const auto& cell : cells) {
            mat[static_cast<size_t>(cell[0] - 1)][static_cast<size_t>(cell[1] - 1)] = i;
            i += 1;
        }

        for (size_t j {0}; j < cols; ++j) {
            heap.push({mat[0][j], 0, j});
            visited[0][j] = true;
        }

        while (!heap.empty()) {
            const auto [curr_day, i, j] = heap.top();
            heap.pop();

            if (i == rows - 1) {
                return curr_day - 1;
            }

            for (const auto& [dx, dy] : DIRECTIONS) {
                const size_t new_i {static_cast<size_t>(static_cast<int>(i) + dx)};
                const size_t new_j {static_cast<size_t>(static_cast<int>(j) + dy)};

                if (new_i >= rows || new_j >= cols || visited[new_i][new_j]) {
                    continue;
                }

                const int new_day {min(curr_day, mat[new_i][new_j])};
                visited[new_i][new_j] = true;
                heap.push({new_day, new_i, new_j});
            }
        }

        return -1;
    }
};
