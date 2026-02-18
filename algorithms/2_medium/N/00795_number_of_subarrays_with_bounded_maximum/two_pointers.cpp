class Solution {
    static inline size_t count_subarrays(
        const vector<int>& nums,
        const size_t start,
        const size_t end,
        const int max_lower_bound
    ) {
        if (start == end) {
            return 0;
        }

        const size_t width{ end - start };
        const size_t total_possible_subarrays{ width * (width + 1) / 2 };
        size_t invalid_counts{ 0 };
        size_t left{ start };

        for (size_t right{ start }; right < end; ++right) {
            if (nums[right] >= max_lower_bound) {
                const size_t invalid_width{ right - left };
                invalid_counts += (invalid_width * (invalid_width + 1)) / 2;
                left = right + 1;
            }
        }

        const size_t invalid_width{ end - left };
        invalid_counts += (invalid_width * (invalid_width + 1)) / 2;

        return total_possible_subarrays - invalid_counts;
    }
public:
    static int numSubarrayBoundedMax(const vector<int>& nums, const int max_lower_bound, const int max_upper_bound) {
        const size_t len{ nums.size() };
        size_t start{ 0 };
        size_t count{ 0 };

        for (size_t end{ 0 }; end < len; ++end) {
            if (nums[end] > max_upper_bound) {
                count += count_subarrays(nums, start, end, max_lower_bound);
                start = end + 1;
            }
        }

        count += count_subarrays(nums, start, len, max_lower_bound);

        return static_cast<int>(count);
    }
};
