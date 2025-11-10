class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        const size_t x_usize{static_cast<size_t>(x)}, y_usize{static_cast<size_t>(y)}, k_usize{static_cast<size_t>(k)};

        for (size_t y_ofs{0}; y_ofs < k_usize; ++y_ofs) {
            size_t lower{x_usize};
            size_t upper{x_usize + k_usize - 1};
            const size_t curr_y{y_usize + y_ofs};

            while (lower < upper) {
                const int temp{grid[lower][curr_y]};
                grid[lower][curr_y] = grid[upper][curr_y];
                grid[upper][curr_y] = temp;

                lower += 1;
                upper -= 1;
            }
        }

        return grid;
    }
};
