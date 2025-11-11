class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        const size_t n{grid.size()};
        int count_up_down{0};
        int count_left_right{0};
        int count_front_back{0};

        for (size_t i{0}; i < n; ++i) {
            int max_left_right{0};

            for (size_t j{0}; j < n; ++j) {
                if (grid[i][j] > 0) {
                    count_up_down += 1;
                }

                max_left_right = max(max_left_right, grid[i][j]);
            }

            count_left_right += max_left_right;
        }

        for (size_t j{0}; j < n; ++j) {
            int max_front_back{0};

            for (size_t i{0}; i < n; ++i) {
                max_front_back = max(max_front_back, grid[i][j]);
            }

            count_front_back += max_front_back;
        }

        return count_front_back + count_left_right + count_up_down;
    }
};
