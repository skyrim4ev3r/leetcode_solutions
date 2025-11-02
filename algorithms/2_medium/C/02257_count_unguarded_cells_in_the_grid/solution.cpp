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

        bool is_covered{false};

        for (size_t j{0}; j < cols; ++j) {
            is_covered = false;
            for (size_t i{rows - 1}; i < rows; --i) {
                if (grid[i][j] == 'g') {
                    is_covered = true;
                } else if (grid[i][j] == 'w') {
                    is_covered = false;
                } else if (is_covered) {
                    grid[i][j] = 'c';
                }
            }

            is_covered = false;
            for (size_t i{0}; i < rows; ++i) {
                if (grid[i][j] == 'g') {
                    is_covered = true;
                } else if (grid[i][j] == 'w') {
                    is_covered = false;
                } else if (is_covered) {
                    grid[i][j] = 'c';
                }
            }
        }

        for (size_t i{0}; i < rows; ++i) {
            is_covered = false;
            for (size_t j{cols - 1}; j < cols; --j) {
                if (grid[i][j] == 'g') {
                    is_covered = true;
                } else if (grid[i][j] == 'w') {
                    is_covered = false;
                } else if (is_covered) {
                    grid[i][j] = 'c';
                }
            }

            is_covered = false;
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 'g') {
                    is_covered = true;
                } else if (grid[i][j] == 'w') {
                    is_covered = false;
                } else if (is_covered) {
                    grid[i][j] = 'c';
                }
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
