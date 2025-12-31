class Solution {
    static inline vector<array<int, 2>> create_starts(const vector<vector<int>>& intervals) {
        vector<array<int, 2>> starts;
        starts.reserve(intervals.size());

        for (int i {0}; const auto& interval : intervals) {
            starts.push_back({interval[0], i});
            i += 1;
        }

        ranges::sort(starts, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        return starts;
    }
public:
    static vector<int> findRightInterval(const vector<vector<int>>& intervals) {
        const size_t len {intervals.size()};
        const vector<array<int, 2>> starts {create_starts(intervals)};
        vector<int> res;
        res.reserve(len);

        for (const auto& interval : intervals) {
            const size_t pos {static_cast<size_t>(lower_bound(
                starts.begin(),
                starts.end(),
                interval[1],
                [](const auto& a, const int& b) {
                    return a[0] < b;
                }
            ) - starts.begin())};

            if (pos == len) {
                res.push_back(-1);
            } else {
                res.push_back(starts[pos][1]);
            }
        }

        return res;
    }
};
