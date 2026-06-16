typedef ptrdiff_t isize;

static bool dfs(const int* nums, const isize len, const isize curr_idx,
                const int curr_sum, const int target, bool* memo)
{
    if (curr_sum == target) {
        return true;
    }

    if (curr_sum > target || curr_idx >= len) {
        return false;
    }

    const isize memo_idx = curr_idx * target + curr_sum;

    if (!memo[memo_idx]) {
        return false;
    }

    const bool res = dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, memo) ||
                     dfs(nums, len, curr_idx + 1, curr_sum, target, memo);
    memo[memo_idx] = res;
    return res;
}

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
    bool* memo = malloc((size_t)(len * target) * sizeof(*memo));
    assert(memo != NULL);
    memset(memo, 1, (size_t)(len * target) * sizeof(*memo));

    const bool res = dfs(nums, len, 0, 0, target, memo);

/* cleanup: */
    free(memo);
    return res;
}
