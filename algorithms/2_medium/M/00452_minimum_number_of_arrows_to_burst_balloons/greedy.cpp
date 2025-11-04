class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {return a[1] < b[1];});

        const size_t len{points.size()};
        int count {1};
        int prev_end{points[0][1]};

        for (size_t i{1}; i < len; ++i) {
            if (points[i][0] > prev_end) {
                prev_end = points[i][1];
                count += 1;
            }
        }

        return count;
    }
};
