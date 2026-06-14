struct DpCell {
    int val;
    bool overflowed;
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        assert(amount >= 0 && amount < numeric_limits<int>::max());
        auto dp = vector<DpCell>(static_cast<size_t>(amount) + 1, DpCell { val: 0, overflowed: false});
        dp[0].val = 1;

        for (const auto coin : coins) {
            for (int i = coin; i <= amount; i += 1) {
                if (dp[i].overflowed) {
                    // already overflowed, nothing to do
                    continue;
                }

                if (dp[i - coin].overflowed || dp[i - coin].val > INT_MAX - dp[i].val) {
                    dp[i].overflowed = true;
                } else {
                    dp[i].val += dp[i - coin].val;
                }
            }
        }

        assert(!dp[amount].overflowed);
        return dp[amount].val;
    }
};
