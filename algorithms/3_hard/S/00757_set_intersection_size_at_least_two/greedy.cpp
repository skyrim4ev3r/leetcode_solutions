class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int count{0};
        int max1{numeric_limits<int>::min()};
        int max2{numeric_limits<int>::min()};

        for (const auto& interval : intervals) {
            if (interval[0] == max1) {
                max2 = max1;
                count += 1;
                max1 = interval[1];
            } else if (interval[0] > max1) {
                max1 = interval[1];
                max2 = max1 - 1;
                count += 2;
            } else if (interval[0] > max2) {
                max2 = max1;
                max1 = interval[1];
                count += 1;
            }
        }

        return count;
    }
};
