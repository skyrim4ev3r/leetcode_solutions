const size_t MAX_VALID_BIT{ 31 };

class Solution {
    static inline int calc_lis_with_mask(const vector<int>& nums, const int mask) {
        vector<int> sub{};

        for (const auto& num : nums) {
            if ((num & mask) == 0) {
                continue;
            }

            const size_t pos{ static_cast<size_t>(ranges::lower_bound(sub, num) - sub.cbegin()) };
            if (pos < sub.size()) {
                sub[pos] = num;
            } else {
                sub.push_back(num);
            }
        }

        return static_cast<int>(sub.size());
    }
public:
    static int longestSubsequence(const vector<int>& nums) {
        int longest{ 0 };

        for (size_t i{ 0 }; i < MAX_VALID_BIT; ++i) {
            const int mask{ 1 << i };

            longest = std::max(longest, calc_lis_with_mask(nums, mask));
        }

        return longest;
    }
};
