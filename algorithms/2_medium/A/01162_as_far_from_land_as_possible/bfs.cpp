const array<array<int, 2>, 4> DIRECTIONS{ array<int,2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const size_t n{ grid.size() };
        queue<pair<size_t, size_t>> q;

        for (size_t i{ 0 }; i < n; ++i) {
            for (size_t j{ 0 }; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n) {
            return -1;
        }

        int curr_level{ 0 };

        while (!q.empty()) {
            const size_t curr_len{ q.size() };
            curr_level += 1;

            for (size_t x{ 0 }; x < curr_len; ++x) {
                const auto [i, j] = q.front();
                q.pop();

                for (const auto& [dx, dy] : DIRECTIONS) {
                    const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx)};
                    const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy)};

                    if (new_i >= n || new_j >= n || grid[new_i][new_j] == 1) {
                        continue;
                    }

                    grid[new_i][new_j] = 1;
                    q.push({new_i, new_j});
                }
            }
        }

        return curr_level - 1;
    }
};
