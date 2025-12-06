class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const size_t n{grid.size()};
        int repeated{0};
        int missed{0};

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                size_t val{static_cast<size_t>(abs(grid[i][j]))};
                size_t other_i{((val + n - 1) / n) - 1};
                size_t other_j{val % n};

                if (other_j == 0) {
                    other_j = n - 1;
                } else {
                    other_j -= 1;
                }

                if (grid[other_i][other_j] < 0) {
                    repeated = abs(grid[i][j]);
                } else {
                    grid[other_i][other_j] *= -1;
                }
            }
        }

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                if (grid[i][j] > 0) {
                    missed = static_cast<int>(i * n + (j + 1));
                    return vector<int>{repeated, missed};
                }
            }
        }

        return vector<int>{-1, -1};
    }
};
