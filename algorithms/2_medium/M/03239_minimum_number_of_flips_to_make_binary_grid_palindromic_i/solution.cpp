class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const size_t rows{ grid.size() };
        const size_t cols{ grid[0].size() };
        int row_cost{ 0 };
        int col_cost{ 0 };

        for (size_t i{ 0 }; i < rows / 2; ++i) {
            const size_t other_i{ rows - 1 - i };

            for (size_t j{ 0 }; j < cols; ++j) {
                if (grid[i][j] != grid[other_i][j]) {
                    row_cost += 1;
                }
            }
        }

        for (size_t j{ 0 }; j < cols / 2; ++j) {
            const size_t other_j{ cols - 1 - j };

            for (size_t i { 0 }; i < rows; ++i) {
                if (grid[i][j] != grid[i][other_j]) {
                    col_cost += 1;
                }
            }
        }

        return std::min(col_cost, row_cost);
    }
};
