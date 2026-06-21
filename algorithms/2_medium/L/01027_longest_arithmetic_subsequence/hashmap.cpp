typedef ptrdiff_t isize;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const isize len = std::ssize(nums);
        if (len <= 2) { return static_cast<int>(len); }

        auto dp = vector<unordered_map<int, int>>(len, unordered_map<int, int>());
        int res = 0;

        for (isize i = len - 1; i >= 0; i -= 1) {
            for (isize j = len - 1; j > i; j -= 1) {
                const int diff = nums[i] - nums[j];
                const auto prev_it = dp[j].find(diff);
                const int prev = prev_it == dp[j].end() ? 1 : prev_it->second;
                const int curr = prev + 1;
                auto [it, inserted] = dp[i].emplace(diff, curr);
                if (!inserted) {
                    it->second = std::max(it->second, curr);
                }
                res = std::max(res, curr);
            }
        }

        return res;
    }
};
