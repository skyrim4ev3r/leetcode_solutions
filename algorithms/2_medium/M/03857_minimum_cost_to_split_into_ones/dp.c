int minCost(int n)
{
    assert(n > 0 && n != INT_MAX);
    if (n == 1) { return 0; }
    if (n == 2) { return 1; }

    int* dp = malloc((size_t)(n + 1) * sizeof(*dp));
    assert(dp != NULL);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i += 1) {
        const int half = i / 2;
        const int other = i - half;
        dp[i] = (half * other) + dp[half] + dp[other];
    }

/* cleanup: */
    const int res = dp[n];
    free(dp);
    return res;
}
