static int backtrack(int* memo, const int* nums, const ptrdiff_t nums_len, const int target)
{
    if (target == 0) { return 1; }
    if (target < 0) { return 0; }
    if (memo[target] != -1) { return memo[target]; }

    int res = 0;

    for (ptrdiff_t i = 0; i < nums_len; ++i) {
        res += backtrack(memo, nums, nums_len, target - nums[i]);
    }

    memo[target] = res;
    return res;
}

int combinationSum4(int* nums, int nums_size, int target)
{
    assert(target > 0);
    const ptrdiff_t dp_len = target + 1;
    int* memo = malloc((size_t)dp_len * sizeof(*memo));
    assert(memo != NULL);
    for (ptrdiff_t i = 0; i < dp_len; i += 1) {
        memo[i] = -1;
    }

    int res = backtrack(memo, nums, nums_size, target);
/* cleanup: */
    free(memo);
    return res;
}
