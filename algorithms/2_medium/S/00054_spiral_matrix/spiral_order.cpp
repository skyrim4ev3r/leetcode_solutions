class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int DIRECTIONS[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        const size_t rows = matrix.size();
        const size_t cols = matrix[0].size();
        const size_t total_nums = rows * cols;

        vector<int> res;
        res.reserve(total_nums);
        auto is_seen{vector<vector<bool>>(rows, vector<bool>(cols, false))};

        size_t i{0};
        size_t j{0};

        size_t curr_dir_index{0};

        for (int k{0}; k < total_nums; ++k) {
            res.push_back(matrix[i][j]);
            is_seen[i][j] = true;

            int dx{DIRECTIONS[curr_dir_index][0]};
            int dy{DIRECTIONS[curr_dir_index][1]};

            size_t next_i{static_cast<size_t>(static_cast<int>(i) + dx)};
            size_t next_j{static_cast<size_t>(static_cast<int>(j) + dy)};

            if (next_i >= rows || next_j >= cols || is_seen[next_i][next_j]) {
                curr_dir_index = (curr_dir_index + 1) % 4;

                int dx{DIRECTIONS[curr_dir_index][0]};
                int dy{DIRECTIONS[curr_dir_index][1]};

                i = static_cast<size_t>(static_cast<int>(i) + dx);
                j = static_cast<size_t>(static_cast<int>(j) + dy);
            } else {
                i = next_i;
                j = next_j;
            }
        }

        return res;
    }
};
