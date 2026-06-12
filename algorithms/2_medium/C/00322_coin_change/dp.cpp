class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        assert(std::ssize(coins) > 0 && amount >= 0);
        const ptrdiff_t dp_len = static_cast<ptrdiff_t>(amount) + 1;
        auto dp = vector<int>(dp_len, amount + 1);
        dp[0] = 0;

        for (const auto c : coins) {
            assert(c > 0);
            const ptrdiff_t c_isize = c;
            for (ptrdiff_t a = c_isize; a < dp_len; a += 1) {
                dp[a] = min(dp[a], dp[a - c_isize] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
