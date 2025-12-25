class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        ranges::sort(points, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int max {0};
        const size_t len {points.size()};

        for (size_t i{0}; i < len - 1; ++i) {
            max = std::max(max, points[i + 1][0] - points[i][0]);
        }

        return max;
    }
};
