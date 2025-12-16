class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const size_t m{grid.size()};
        const size_t n{grid[0].size()};
        size_t res{0};

        for (size_t i{0}; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (size_t j{0}; j < n; ++j) {
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
                }
            }
        }

        for (size_t j{0}; j < n; ++j) {
            size_t count_ones{0};

            for (size_t i{0}; i < m; ++i) {
                if (grid[i][j] == 1) {
                    count_ones +=1;
                }
            }

            const size_t max{std::max(count_ones, m - count_ones)};
            const size_t pow{n - 1 - j};

            res += max * (std::pow(2, pow));
        }

        return static_cast<int>(res);
    }
};
