class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const size_t len{ nums.size() };
        unordered_map<int, size_t> diff_to_len_map{};
        int count_zeros{ 0 };
        int count_ones{ 0 };
        size_t longest{ 0 };

        diff_to_len_map[0] = 0;

        for (size_t i{ 0 }; i < len; ++i) {
            if (nums[i] == 0) {
                count_ones += 1;
            } else {
                count_zeros += 1;
            }

            const auto it{ diff_to_len_map.find(count_ones - count_zeros) };

            if (it != diff_to_len_map.end()) {
                longest = std::max(longest, i + 1 - it->second);
            } else {
                diff_to_len_map[count_ones - count_zeros] = i + 1;
            }
        }

        return static_cast<int>(longest);
    }
};
