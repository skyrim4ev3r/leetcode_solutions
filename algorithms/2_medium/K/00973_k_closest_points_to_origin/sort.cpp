class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ranges::sort(points, [](const auto& a, const auto &b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        points.resize(static_cast<size_t>(k), vector<int>{});

        return points;
    }
};
