class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        size_t left{0};
        size_t zero_count{0};
        size_t max_subarr_len{0};
        const size_t len{nums.size()};

        for (size_t right{0}; right < len; ++right) {
            if (nums[right] == 0) {
                zero_count += 1;
            }

            while (zero_count > 1) {
                if (nums[left] == 0) {
                    zero_count -= 1;
                }

                left += 1;
            }

            max_subarr_len = std::max(max_subarr_len, right - left + 1 - zero_count);
        }

        // Edge case: if entire arr is 1, then max_subarr_len will be equal to len
        // need to delete at least one of them
        if (max_subarr_len == len) {
            return static_cast<int>(max_subarr_len) - 1;
        }

        return static_cast<int>(max_subarr_len);
    }
};
