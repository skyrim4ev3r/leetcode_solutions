constexpr int64_t mod = 1'000'000'007;

class Solution {
public:
    static int knightDialer(const int n) {
        int64_t dp[20] = { 0 };
        auto curr = std::span<int64_t>(&dp[0], 10);
        auto next = std::span<int64_t>(&dp[10], 10);
        std::fill(next.begin(), next.end(), 1);

        for (int i = 1; i < n; i += 1) {
            curr[0] = (next[4] + next[6]) % mod;
            curr[7] = (next[2] + next[6]) % mod;
            curr[9] = (next[4] + next[2]) % mod;
            curr[8] = (next[1] + next[3]) % mod;
            curr[4] = (next[0] + next[9] + next[3]) % mod;
            curr[6] = (next[1] + next[7] + next[0]) % mod;
            curr[1] = (next[6] + next[8]) % mod;
            curr[2] = (next[7] + next[9]) % mod;
            curr[3] = (next[4] + next[8]) % mod;
            curr[5] = 0;

            std::swap(curr, next);
        }

        return static_cast<int>(std::reduce(next.begin(), next.end(), 0LL) % mod);
    }
};
