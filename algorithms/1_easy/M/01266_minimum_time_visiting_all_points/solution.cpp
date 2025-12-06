class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cost{0};
        const size_t len{points.size()};

        for (size_t i{1}; i < len; ++i) {
            cost += std::max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }

        return cost;
    }
};
