class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const size_t rows {grid.size()};
        const size_t cols {grid[0].size()};
        vector<int> prefix_cols(cols, 0);
        vector<int> prefix_rows(rows, 0);
        long long count {0};

        for (size_t i {0}; i < rows; ++i) {
            for (size_t j {0}; j < cols; ++j) {
                prefix_cols[j] += grid[i][j];
                prefix_rows[i] += grid[i][j];
            }
        }

        for (size_t i {0}; i < rows; ++i) {
            for (size_t j {0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    count += static_cast<long long>(prefix_rows[i] - 1) * static_cast<long long>(prefix_cols[j] - 1);
                }
            }
        }

        return count;
    }
};
