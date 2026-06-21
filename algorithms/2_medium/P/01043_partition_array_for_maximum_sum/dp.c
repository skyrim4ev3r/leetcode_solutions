typedef ptrdiff_t isize;

const isize min_isize(const isize a, const isize b)
{
    return a < b ? a : b;
}

const int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maxSumAfterPartitioning(int* arr, int arr_size, int k_i32)
{
    assert(arr != NULL && arr_size >= 0 && k_i32 > 0);
    const isize k = k_i32;
    const isize len = arr_size;
    int* dp = malloc((size_t)(len + 1) * sizeof(*dp));
    assert(dp != NULL);
    dp[len] = 0;

    for (isize i = len - 1; i >= 0; i -= 1) {
        int val = arr[i];
        int sum = val + dp[i + 1];
        const isize end_j = min_isize(i + k, len);
        for (isize j = i + 1; j < end_j; j += 1) {
            val = max_int(val, arr[j]);
            const int width = (int)(j - i + 1);
            sum = max_int(sum, val * width + dp[j + 1]);
        }
        dp[i] = sum;
    }

/* cleanup: */
    const int res = dp[0];
    free(dp);
    return res;
}
