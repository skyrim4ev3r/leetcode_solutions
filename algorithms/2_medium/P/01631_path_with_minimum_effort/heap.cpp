array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const size_t rows{ heights.size() };
        const size_t cols{ heights[0].size() };
        vector<vector<int>> costs(rows, vector<int>(cols, numeric_limits<int>::max()));
        priority_queue<tuple<int, short, short>> heap{};
        heap.push({0, 0, 0});

        while (!heap.empty()) {
            const auto [negative_cost, i_u16, j_u16] = heap.top();
            heap.pop();
            const int cost{ -negative_cost };
            const size_t i{ static_cast<size_t>(i_u16) };
            const size_t j{ static_cast<size_t>(j_u16) };

            if (i == rows - 1 && j == cols - 1) {
                return cost;
            }

            if (cost > costs[i][j]) {
                continue;
            }

            for (const auto& [dx, dy] : DIRECTIONS) {
                const size_t new_i{ static_cast<size_t>(static_cast<int>(i) + dx) };
                const size_t new_j{ static_cast<size_t>(static_cast<int>(j) + dy) };

                if (new_i >= rows || new_j >= cols) {
                    continue;
                }

                const int move_cost{ abs(heights[i][j] - heights[new_i][new_j]) };
                const int new_cost{ std::max(move_cost, cost) };

                if (new_cost >= costs[new_i][new_j]) {
                    continue;
                }

                costs[new_i][new_j] = new_cost;

                heap.push({-new_cost, static_cast<short>(new_i), static_cast<short>(new_j)});
            }
        }

        return -1;
    }
};
