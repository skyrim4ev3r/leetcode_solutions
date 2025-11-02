class Solution {
    const array<array<int, 2>, 8> directions{array<int, 2>{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const size_t rows{img.size()};
        const size_t cols{img[0].size()};

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (size_t i{0}; i < rows; ++i) {
            for (size_t j{0}; j < cols; ++j) {
                int sum{img[i][j]};
                int count{1};

                for (const auto &[dx, dy]: directions) {
                    size_t new_i{static_cast<size_t>(static_cast<int>(i) + dx)};
                    size_t new_j{static_cast<size_t>(static_cast<int>(j) + dy)};

                    if (new_i >= rows || new_j >= cols) {
                        continue;
                    }

                    count += 1;
                    sum += img[new_i][new_j];
                }

                res[i][j] = sum / count;
            }
        }

        return res;
    }
};
