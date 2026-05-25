int uniquePaths(int m, int n)
{
    const size_t rows = m > n ? m : n;
    const size_t cols = m > n ? n : m;
    int *dp = (int*) malloc(cols * sizeof(int));
    int *dp_next = (int*) malloc(cols * sizeof(int));

    for (size_t j = 0; j < cols; j += 1) {
        dp[j] = 1;
    }

    for (size_t i = 1; i < rows; i += 1) {
        dp_next[0] = 1;
        for (size_t j = 1; j < cols; j += 1) {
            dp_next[j] = dp_next[j - 1] + dp[j];
        }
        int *temp = dp;
        dp = dp_next;
        dp_next = temp;
    }

    const int res = dp[cols - 1];
    free(dp);
    free(dp_next);

    return res;
}
