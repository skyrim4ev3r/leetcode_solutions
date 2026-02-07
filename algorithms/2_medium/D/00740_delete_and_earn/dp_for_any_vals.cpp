class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freqs{};

        for (const auto& num : nums) {
            freqs[num] += 1;
        }

        vector<pair<int, int>> dp;
        const size_t dp_len{ freqs.size() };
        dp.reserve(dp_len);

        for (const auto& [val, freq] : freqs) {
            dp.push_back({ val, val * freq });
        }

        ranges::sort(dp, [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        if (dp_len == 1) {
            return dp[0].second;
        }

        if (dp[0].first + 1 < dp[1].first) {
            dp[1].second += dp[0].second;
        }

        if (dp_len == 2) {
            return std::max(dp[0].second, dp[1].second);
        }

        if (dp[1].first + 1 < dp[2].first) {
            dp[2].second += std::max(dp[0].second, dp[1].second);
        } else {
            dp[2].second += dp[0].second;
        }

        for (size_t i{ 3 }; i < dp_len; ++i) {
            if (dp[i - 1].first + 1 < dp[i].first) {
                dp[i].second += std::max(dp[i - 1].second, dp[i - 2].second);
            } else {
                dp[i].second += std::max(dp[i - 2].second, dp[i - 3].second);
            }
        }

        return std::max(dp[dp_len - 1].second, dp[dp_len - 2].second);
    }
};
