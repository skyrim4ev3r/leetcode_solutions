class Solution {
    static inline int rob_helper(vector<int>& dp) {
        const size_t len{ dp.size() };

        dp[2] += dp[0];

        for (size_t i{3}; i < len; ++i) {
            dp[i] += std::max(dp[i - 2], dp[i - 3]);
        }

        return std::max(dp[len - 1], dp[len - 2]);
    }
public:
    static int rob(const vector<int>& nums) {
        if (nums.size() <= 3) {
            return *std::max_element(nums.cbegin(), nums.cend());
        }

        vector<int> dp1(nums.cbegin() + 1, nums.cend());
        vector<int> dp2(nums.cbegin(), nums.cend() - 1);

        const int max_dp1{ rob_helper(dp1) };
        const int max_dp2{ rob_helper(dp2) };

        return std::max(max_dp1, max_dp2);
    }
};
