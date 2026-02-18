class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const size_t len{ nums.size() };
        vector<int> diff_to_len_vec(2 * len + 1, numeric_limits<int>::max());
        size_t count_zeros{ 0 };
        size_t count_ones{ 0 };
        int longest{ 0 };

        diff_to_len_vec[len] = 0;

        for (size_t i{ 0 }; i < len; ++i) {
            if (nums[i] == 0) {
                count_ones += 1;
            } else {
                count_zeros += 1;
            }

            const size_t index{ count_ones - count_zeros + len };

            if (diff_to_len_vec[index] != numeric_limits<int>::max()) {
                longest = std::max(longest, static_cast<int>(i) + 1 - diff_to_len_vec[index]);
            } else {
                diff_to_len_vec[index] = static_cast<int>(i) + 1;
            }
        }

        return longest;
    }
};
