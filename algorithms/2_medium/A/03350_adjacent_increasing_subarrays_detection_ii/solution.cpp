class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        const size_t len{nums.size()};
        int max_adjacent_inc_len{0};
        int max_single_inc_len{0};
        int prev_inc_len{0};
        int curr_inc_len{1};

        for (size_t i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                curr_inc_len += 1;
            } else {
                max_adjacent_inc_len = std::max(max_adjacent_inc_len, std::min(curr_inc_len, prev_inc_len));
                max_single_inc_len = std::max(max_single_inc_len, curr_inc_len);
                prev_inc_len = curr_inc_len;
                curr_inc_len = 1;
            }
        }

        max_adjacent_inc_len = std::max(max_adjacent_inc_len, std::min(curr_inc_len, prev_inc_len));
        max_single_inc_len = std::max(max_single_inc_len, curr_inc_len);

        return std::max(max_adjacent_inc_len, max_single_inc_len / 2);
    }
};
