class Solution {
public:
    static long long minOperations(const vector<int>& nums1, const vector<int>& nums2) {
        const size_t len{ nums1.size() };
        const int extra_num{ nums2.back() };
        int extra_num_min_cost{ numeric_limits<int>::max()};
        long long total_cost{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            const int min{ std::min(nums1[i], nums2[i]) };
            const int max{ std::max(nums1[i], nums2[i]) };
            total_cost += static_cast<long long>(max - min);

            if (extra_num >= min && extra_num <= max) {
                extra_num_min_cost = 0;
            } else if (extra_num > max) {
                extra_num_min_cost = std::min(extra_num_min_cost, extra_num - max);
            } else {
                extra_num_min_cost = std::min(extra_num_min_cost, min - extra_num);
            }
        }

        return total_cost + 1 + extra_num_min_cost;
    }
};
