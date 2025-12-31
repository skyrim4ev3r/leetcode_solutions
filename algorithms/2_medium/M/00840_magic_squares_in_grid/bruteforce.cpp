class Solution {
    static inline bool check_sub_mat(const vector<vector<int>>& grid, const size_t i_st, const size_t j_st) {
        array<bool, 10> seen {};

        for (size_t i {i_st}; i < i_st + 3; ++i) {
            for (size_t j {j_st}; j < j_st + 3; ++j) {
                const int val {grid[i][j]};

                if (val < 1 || val > 9) {
                    return false;
                }

                if (seen[static_cast<size_t>(val)]) {
                    return false;
                }

                seen[static_cast<size_t>(val)] = true;
            }
        }

        const int sum {grid[i_st][j_st] + grid[i_st + 1][j_st] + grid[i_st + 2][j_st]};

        for (size_t i {i_st}; i < i_st + 3; ++i) {
            if (grid[i][j_st] + grid[i][j_st + 1] + grid[i][j_st + 2] != sum) {
                return false;
            }
        }

        for (size_t j {j_st + 1}; j < j_st + 3; ++j) {
            if (grid[i_st][j] + grid[i_st + 1][j] + grid[i_st + 2][j] != sum) {
                return false;
            }
        }

        if (
            grid[i_st][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st + 2][j_st + 2] != sum ||
            grid[i_st + 2][j_st] + grid[i_st + 1][j_st + 1] + grid[i_st][j_st + 2] != sum
        ) {
            return false;
        }

        return true;
    }
public:
    static int numMagicSquaresInside(const vector<vector<int>>& grid) {
        const size_t rows {grid.size()};
        const size_t cols {grid[0].size()};
        int count {0};

        for (size_t i {0}; i + 2 < rows; ++i) {
            for (size_t j {0}; j + 2 < cols; ++j) {
                if (check_sub_mat(grid, i, j)) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
