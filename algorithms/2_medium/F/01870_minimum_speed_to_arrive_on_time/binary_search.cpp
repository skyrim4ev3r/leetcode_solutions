class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (static_cast<size_t>(std::ceil(hour)) <= dist.size() - 1) {
            return -1;
        }

        int high{ 10'000'000 };
        int low{ 1 };
        const size_t len{ dist.size() };

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };
            int curr_cost_i32{ 0 };

            for (size_t i{ 0 }; i + 1 < len; ++i) {
                curr_cost_i32 += (dist[i] + mid - 1) / mid; 
            }

            const double curr_cost{ 
                static_cast<double>(curr_cost_i32) + 
                static_cast<double>(dist[len - 1]) / static_cast<double>(mid)
            };

            if (curr_cost <= hour) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
