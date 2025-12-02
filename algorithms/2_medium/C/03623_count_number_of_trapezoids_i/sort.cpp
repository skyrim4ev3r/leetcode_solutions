class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        const long long MOD_TO{1000000007};
        long long total_trapezoid_count{0};
        long long total_selection{0};
        long long count{0};
        int prev_y{numeric_limits<int>::min()};

        for (const auto& point : points) {
            if (point[1] == prev_y) {
                count += 1;
            } else {
                if (count > 1) {
                    long long curr_selection{((count * (count - 1)) / 2) % MOD_TO};
                    total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
                    total_selection = (total_selection + curr_selection) % MOD_TO;
                }
                
                prev_y = point[1];
                count = 1;
            }
        }

        if (count > 1) {
            long long curr_selection{((count * (count - 1)) / 2) % MOD_TO};
            total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
        }

        return static_cast<int>(total_trapezoid_count);
    }
};
