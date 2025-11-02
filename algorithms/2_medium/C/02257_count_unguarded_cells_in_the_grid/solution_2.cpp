class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        const size_t rows{static_cast<size_t>(m)};
        const size_t cols{static_cast<size_t>(n)};

        vector<vector<char>> grid(rows, vector<char>(cols, '.'));

        for (const auto &guard: guards) {
            grid[static_cast<size_t>(guard[0])][static_cast<size_t>(guard[1])] = 'g';
        }

        for (const auto &wall: walls) {
            grid[static_cast<size_t>(wall[0])][static_cast<size_t>(wall[1])] = 'w';
        }

        for (const auto& guard : guards) {
            const size_t x{static_cast<size_t>(guard[0])};
            const size_t y{static_cast<size_t>(guard[1])};

            for (size_t i {x - 1}; i < rows && grid[i][y] !='g' && grid[i][y] != 'w'; --i) {
                grid[i][y] = 'c';
            }

            for (size_t i {x + 1}; i < rows && grid[i][y] !='g' && grid[i][y] != 'w'; ++i) {
                grid[i][y] = 'c';
            }

            for (size_t j{y - 1}; j < cols && grid[x][j] != 'g' && grid[x][j] != 'w'; --j) {
                grid[x][j] = 'c';
            }

            for (size_t j{y + 1}; j < cols && grid[x][j] != 'g' && grid[x][j] != 'w'; ++j) {
                grid[x][j] = 'c';
            }
        }

        int count{0};
        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == '.') {
                    count += 1;
                }
            }
        }

        return count;
    }
};
