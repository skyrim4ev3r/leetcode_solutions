class Solution {
    const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const size_t rows{mat.size()};
        const size_t cols{mat[0].size()};

        vector<vector<int>> res(rows, vector<int>(cols, 0));
        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        queue<pair<size_t, size_t>> q;

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    is_visited[i][j] = true;
                }
            }
        }

        int curr_level{0};

        while (!q.empty()) {
            const size_t curr_len{q.size()};

            for (size_t k{0}; k < curr_len; ++k) {
                const auto [i, j] = q.front();
                res[i][j] = curr_level;
                q.pop();

                for (const auto& [dx, dy] : DIRECTIONS) {
                    const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                    const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                    if (new_i >= rows || new_j >= cols || is_visited[new_i][new_j]) {
                        continue;
                    }

                    is_visited[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            }

            curr_level += 1;
        }

        return res;
    }
};
