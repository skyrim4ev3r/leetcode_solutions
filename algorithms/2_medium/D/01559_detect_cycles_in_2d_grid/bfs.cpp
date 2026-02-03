const array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{1, 0}, {0, 1}, {-1, 0}, {0, -1} };

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        for (size_t i{ 0 }; i < rows; ++i) {
            for (size_t j{ 0 }; j < cols; ++j) {
                if (!visited[i][j]) {
                    const char parent_char{ grid[i][j] };
                    visited[i][j] = true;
                    q.push({static_cast<int>(i), static_cast<int>(j)});

                    while (!q.empty()) {
                        const auto [old_i, old_j] = q.front();
                        q.pop();
                        int count{ 0 };

                        for (const auto& [dx, dy] : DIRECTIONS) {
                            const size_t new_i{ static_cast<size_t>(old_i + dx) };
                            const size_t new_j{ static_cast<size_t>(old_j + dy) };

                            if (new_i >= rows || new_j >= cols || grid[new_i][new_j] != parent_char) {
                                continue;
                            }

                            if (visited[new_i][new_j]) {
                                count += 1;

                                if (count >= 2) {
                                    return true;
                                }

                                continue;
                            }

                            visited[new_i][new_j] = true;
                            q.push({static_cast<int>(new_i), static_cast<int>(new_j)});
                        }
                    }
                }

            }
        }

        return false;
    }
};
