class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const size_t len{ nums.size() };
        vector<int> dp(len, -1);
        dp[0] = 0;

        for (size_t i{ 0 }; i < len; ++i) {
            if (dp[i] == -1) {
                continue;
            }

            for (size_t j{ i + 1 }; j < len; ++j) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[j] = std::max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[len - 1];
    }
};
