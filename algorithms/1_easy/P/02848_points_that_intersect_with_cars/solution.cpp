class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int count{0};
        int prev_right_point{numeric_limits<int>::min()};

        for (const auto& point : nums) {
            if (prev_right_point >=  point[1]) {
                continue;
            }

            if (prev_right_point >=  point[0]) {
                count += point[1] - prev_right_point;
                prev_right_point = point[1];
            } else {
                count += point[1] - point[0] + 1;
                prev_right_point = point[1];
            }
        }

        return count;
    }
};
