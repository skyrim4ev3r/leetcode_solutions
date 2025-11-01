class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box_grid) {
        const size_t original_rows{box_grid.size()};
        const size_t original_cols{box_grid[0].size()};

        const size_t rows{original_cols};
        const size_t cols{original_rows};

        vector<vector<char>> res(rows, vector<char>(cols, '.'));
        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                res[i][j] = box_grid[cols - j - 1][i];
            }
        }

        for (size_t j{0}; j < cols; ++j) {

            size_t top{0};
            size_t bottom{0};

            while (bottom < rows) {
                int leaf_count{0};

                while (bottom < rows && res[bottom][j] != '*') {
                    if (res[bottom][j] == '#') {
                        leaf_count += 1;
                        res[bottom][j] = '.';
                    }

                    bottom += 1;
                }

                for (size_t i{bottom - leaf_count}; i < bottom; ++i) {
                    res[i][j] = '#';
                }

                bottom = bottom + 1;
                top = bottom;
            }
        }

        return res;
    }
};
