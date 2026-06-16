typedef ptrdiff_t isize;

static inline int calc_sum(const int* nums, const isize len)
{
    int sum = 0;
    for (isize i = 0; i < len; i += 1) {
        assert(nums[i] >= 0 && INT_MAX - sum >= nums[i]);
        sum += nums[i];
    }
    return sum;
}

bool canPartition(int* nums, int nums_size)
{
    const isize len = nums_size;
    assert(nums != NULL && len > 0);
    const int sum = calc_sum(nums, len);
    if ((sum & 1) == 1) { return false; }

    const int target = sum / 2;
    bool* dp = calloc((size_t)target + 1, sizeof(*dp));
    assert(dp != NULL);
    dp[target] = true;
    bool res = false;

    for (isize i = len - 1; i >= 0; i -= 1) {
        const int num = nums[i];

        if (num > target) {
            // all nums are positive, so this num cant be use in any subsets
            goto cleanup; 
        }

        for (isize j = 0; j <= target - num; j += 1) {
            dp[j] = dp[j] | dp[j + num];
        }

        if (dp[0]) {
            res = true;
            goto cleanup;
        }
    }

cleanup:
    free(dp);
    return res;
}
