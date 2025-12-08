const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    static vector<vector<int>> highestPeak(vector<vector<int>>& is_water) {
        const size_t rows{is_water.size()};
        const size_t cols{is_water[0].size()};
        queue<pair<size_t, size_t>> queue{};
        int curr_height{0};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (is_water[i][j] == 1) {
                    queue.push({i, j});
                }

                is_water[i][j] -= 1;
            }
        }

        while (!queue.empty()) {
            const size_t curr_len{queue.size()};
            curr_height += 1;

            for (size_t k{0}; k < curr_len; ++k) {
                const auto [i, j] = queue.front();
                queue.pop();

                for (const auto& [dx, dy] : DIRECTIONS) {
                    const size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                    const size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                    if (new_i >= rows || new_j >= cols || is_water[new_i][new_j] != -1) {
                        continue;
                    }

                    is_water[new_i][new_j] = curr_height;

                    queue.push({new_i, new_j});
                }

            }
        }

        return is_water;
    }
};
