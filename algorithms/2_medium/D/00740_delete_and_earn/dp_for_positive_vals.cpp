class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const size_t dp_len{ 1 + static_cast<size_t>(*std::max_element(nums.cbegin(), nums.cend())) };
        vector<int> dp(dp_len, 0);

        for (const auto& num : nums) {
            dp[static_cast<size_t>(num)] += num;
        }

        for (size_t i{ 3 }; i < dp_len; ++i) {
            dp[i] += std::max(dp[i - 2], dp[i - 3]);
        }

        return std::max(dp[dp_len - 1], dp[dp_len - 2]);
    }
};
