class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        size_t max_i{0};
        size_t min_i{std::numeric_limits<size_t>::max()};
        size_t max_j{0};
        size_t min_j{std::numeric_limits<size_t>::max()};
        bool found_one = false;  // Flag to check if any '1' is found

        const size_t rows{grid.size()};
        const size_t cols{grid[0].size()};

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    found_one = true;

                    max_i = i; // Directly assign since var "i" is always growing
                    min_i = std::min(min_i, i);

                    max_j = max(max_j, j);
                    min_j = min(min_j, j);
                }
            }
        }

        if (!found_one) {
            return 0;
        }

        return static_cast<int>((max_i - min_i + 1) * (max_j - min_j + 1));
    }
};
