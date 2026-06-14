struct dp_cell {
    int val;
    bool overflowed;
};

int change(int amount, int* coins, int coins_size)
{
    assert(coins != NULL && amount < INT_MAX && amount >= 0);
    struct dp_cell* dp = calloc((size_t)amount + 1, sizeof(*dp));
    dp[0].val = 1;

    for (int coin_idx = 0; coin_idx < coins_size; coin_idx += 1) {
        const int coin = coins[coin_idx];

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
    const int res = dp[amount].val;
/* cleanup: */
    free(dp);
    return res;
}
