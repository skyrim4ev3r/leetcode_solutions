class Solution {
    static inline int count_subarrays_at_max(const vector<int>& nums, const int at_max) {
        int count{ 0 };
        int crr_len{ 0 };

        for (const auto& num : nums) {
            if (num > at_max) {
                crr_len = 0;
            } else {
                crr_len += 1;
            }

            count += crr_len;
        }

        return count;
    }
public:
    static int numSubarrayBoundedMax(const vector<int>& nums, const int max_lower_bound, const int max_upper_bound) {
        return count_subarrays_at_max(nums, max_upper_bound) - count_subarrays_at_max(nums, max_lower_bound - 1);
    }
};
