class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int i, int j) {
        const size_t target_len{static_cast<size_t>(rows * cols)};
        vector<vector<int>> res;
        res.reserve(target_len);
        const array<array<int, 2>, 4> DIRECTIONS{array<int, 2>{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        size_t dir_index{0};
        int curr_path_len{0};
        bool flip_flop_should_increase_path{true};

        while (true) {
            if (flip_flop_should_increase_path) {
                curr_path_len += 1;
            }
            flip_flop_should_increase_path = !flip_flop_should_increase_path;

            for (int k{0}; k < curr_path_len; k += 1) {
                if (i >= 0 && i < rows && j >=0 && j < cols) {
                    res.push_back(vector<int>{i, j});

                    if (res.size() == target_len) {
                        return res;
                    }
                }

                i += DIRECTIONS[dir_index][0];
                j += DIRECTIONS[dir_index][1];
            }

            dir_index = (dir_index + 1) % 4;
        }

        return res;
    }
};
