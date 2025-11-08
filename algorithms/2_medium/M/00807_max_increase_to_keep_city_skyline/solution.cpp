class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        const size_t n{grid.size()};

        vector<int> max_rows;
        max_rows.reserve(n);
        vector<int> max_cols;
        max_cols.reserve(n);

        for (size_t i{0}; i < n; ++i) {
            int max{0};

            for (size_t j{0}; j < n; ++j) {
                max = std::max(max, grid[i][j]);
            }

            max_rows.push_back(max);
        }

        for (size_t j{0}; j < n; ++j) {
            int max{0};

            for (size_t i{0}; i < n; ++i) {
                max = std::max(max, grid[i][j]);
            }

            max_cols.push_back(max);
        }

        int count{0};

        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < n; ++j) {
                count += std::min(max_cols[j], max_rows[i]) - grid[i][j];
            }
        }

        return count;
    }
};
