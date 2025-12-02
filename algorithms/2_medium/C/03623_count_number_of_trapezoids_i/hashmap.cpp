class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> hashmap{};

        const long long MOD_TO{1000000007};
        long long total_trapezoid_count{0};
        long long total_selection{0};

        for (const auto& point : points) {
            hashmap[point[1]] += 1;
        }

        for (const auto& it : hashmap) {
            long long count{static_cast<long long>(it.second)};

            if (count > 1) {
                long long curr_selection{((count * (count - 1)) / 2) % MOD_TO};
                total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
                total_selection = (total_selection + curr_selection) % MOD_TO;
            }
        }

        return static_cast<int>(total_trapezoid_count);
    }
};
