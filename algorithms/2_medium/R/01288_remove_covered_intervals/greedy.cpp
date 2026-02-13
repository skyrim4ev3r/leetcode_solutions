class Solution {
public:
    static int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, [](const auto& a, const auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        });

        const size_t len{ intervals.size() };
        size_t invalids_count{ 0 };
        int prev_end{ intervals[0][1] };

        for (size_t i{ 1 }; i < len; ++i) {
            if (intervals[i][1] <=  prev_end) {
                invalids_count += 1;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return static_cast<int>(len - invalids_count);
    }
};
