class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const size_t m{grid.size()};
        const size_t n{grid[0].size()};
        const size_t shift_counts{static_cast<size_t>(k) % (m * n)};

        if (shift_counts == 0) {
            return grid;
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        size_t res_i{shift_counts / n};
        size_t res_j{shift_counts % n};

        for (size_t i{0}; i < m; ++i) {
            for (size_t j{0}; j < n; ++j) {
                res[res_i][res_j] = grid[i][j];
                res_j += 1;

                if (res_j == n) {
                    res_j = 0;
                    res_i += 1;

                    if (res_i == m) {
                        res_i = 0;
                    }
                }
            }
        }

        return res;
    }
};
