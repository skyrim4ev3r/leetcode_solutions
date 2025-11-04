class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }

            return a[0] < b[0];
        });

        size_t left{0};
        const size_t len{intervals.size()};
        int count {0};

        for (size_t right{1}; right < len; ++right) {
            if (intervals[left][1] <= intervals[right][0]) {
                left = right;
            } else {
                if (intervals[right][1] < intervals[left][1]) {
                    left = right;
                }

                count += 1;
            }
        }

        return count;
    }
};
