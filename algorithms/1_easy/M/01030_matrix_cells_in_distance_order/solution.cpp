class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r_center, int c_center) {
        vector<vector<int>> res;
        res.reserve(static_cast<size_t>(rows * cols));

        for (int i {0}; i < rows; ++i) {
            for (int j {0}; j < cols; ++j) {
                res.push_back(vector<int>{i , j});
            }
        }

        ranges::sort(res, [r_center, c_center](const auto& a, const auto& b) {
            const int da {abs(a[0] - r_center) + abs(a[1] - c_center)};
            const int db {abs(b[0] - r_center) + abs(b[1] - c_center)};

            return da < db;
        });

        return res;
    }
};
