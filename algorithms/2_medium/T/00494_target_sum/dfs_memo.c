#define ISIZE_MAX PTRDIFF_MAX

typedef ptrdiff_t isize;

static int dfs(const int* nums, const isize len, const isize curr_idx, const int curr_sum,
               const int target, const int sum_abs, int* memo, const isize memo_cols)
{
    if (curr_idx == len) {
        return curr_sum == target ? 1 : 0;
    }

    const isize memo_idx = (curr_idx * memo_cols) + (curr_sum + sum_abs);

    if (memo[memo_idx] != - 1) {
        return memo[memo_idx];
    }

    const int res = dfs(nums, len, curr_idx + 1, curr_sum + nums[curr_idx], target, sum_abs, memo, memo_cols) +
                    dfs(nums, len, curr_idx + 1, curr_sum - nums[curr_idx], target, sum_abs, memo, memo_cols);

    memo[memo_idx] = res;
    return res;
}

static int calac_sum_abs(const int* nums, const isize len)
{
    int sum = 0;
    for (isize i = 0; i < len; i += 1) {
        const int abs_num = nums[i] < 0 ? -nums[i] : nums[i];
        assert(INT_MAX - sum >= abs_num);
        sum += abs_num;
    }
    return sum;
}

int findTargetSumWays(int* nums, int nums_size, int target)
{
    assert(nums != NULL && nums_size > 0);
    const isize len = nums_size;
    const int sum_abs = calac_sum_abs(nums, len);

    const isize memo_rows = len;
    const isize memo_cols = 1 + 2 * (isize)sum_abs; // for all vals in range [-sum_abs, sum_abs]
    assert( ISIZE_MAX / memo_cols >= memo_rows);
    const isize memo_size = memo_rows * memo_cols;
    int* memo = malloc((size_t)memo_size * sizeof(*memo));
    assert(memo != NULL);
    for (isize i = 0; i < memo_size; i += 1) {
        memo[i] = -1;
    }

    int res = dfs(nums, len, 0, 0, target, sum_abs, memo, memo_cols);
/* cleanup: */
    free(memo);
    return res;
}
