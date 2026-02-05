const array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    static bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (health - grid[0][0] <= 0) {
            return false;
        }

        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        priority_queue<tuple<int, char, char>> heap;
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        visited[0][0] = true;
        heap.push({ health - grid[0][0], 0, 0 });

        while (!heap.empty()) {
            const auto [prev_health, i_i8, j_i8] = heap.top();
            heap.pop();

            for (const auto& [dx, dy] : DIRECTIONS) {
                const size_t new_i{ static_cast<size_t>(static_cast<int>(i_i8) + dx) };
                const size_t new_j{ static_cast<size_t>(static_cast<int>(j_i8) + dy) };

                if (new_i >= rows || new_j >= cols || visited[new_i][new_j]) {
                    continue;
                }

                const int new_health{ prev_health - grid[new_i][new_j] };

                if (new_i == rows - 1 && new_j == cols - 1) {
                    return new_health > 0;
                }

                if (new_health <= 0) {
                    continue;
                }

                visited[new_i][new_j] = true;
                heap.push({ new_health, static_cast<char>(new_i), static_cast<char>(new_j) });
            }
        }

        return false;
    }
};
