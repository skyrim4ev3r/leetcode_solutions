class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {return a[1] < b[1];});

        const size_t len{intervals.size()};
        int count {0};
        int prev_end{intervals[0][1]};

        for (size_t i{1}; i < len; ++i) {
            if (intervals[i][0] >= prev_end) {
                prev_end = intervals[i][1];
            } else {
                count += 1;
            }
        }

        return count;
    }
};
