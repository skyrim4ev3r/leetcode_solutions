static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

int coinChange(int* coins, int coins_size, int amount)
{
    assert(coins != NULL && coins_size > 0 && amount >= 0);
    const ptrdiff_t coins_len = coins_size;
    const ptrdiff_t dp_len = (ptrdiff_t)amount + 1;
    int* dp = malloc((size_t)dp_len * sizeof(*dp));
    assert(dp != NULL);
    for (ptrdiff_t i = 0; i < dp_len; i += 1) { 
        dp[i] = amount + 1;
    }
    dp[0] = 0;

    for (ptrdiff_t i = 0; i < coins_len; i += 1) {
        assert(coins[i] > 0);
        const ptrdiff_t c_isize = coins[i];
        for (ptrdiff_t a = c_isize; a < dp_len; a += 1) {
            dp[a] = min_int(dp[a], dp[a - c_isize] + 1);
        }
    }

/* cleanup: */
    const int res = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return res;
}
