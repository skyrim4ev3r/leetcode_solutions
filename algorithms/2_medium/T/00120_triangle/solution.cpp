class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (auto i = static_cast<ptrdiff_t>(triangle.size()) - 2; i >= 0; i -= 1) {
            const auto cols = static_cast<ptrdiff_t>(triangle[i].size());

            for (ptrdiff_t j = 0; j < cols; ++j) {
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};
