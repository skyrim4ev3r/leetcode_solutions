#define MIN_ALLOWED_NUM 0
#define MAX_ALLOWED_NUM 500
#define NUMS_DIFF (MAX_ALLOWED_NUM - MIN_ALLOWED_NUM + 1)

typedef ptrdiff_t isize;

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int longestArithSeqLength(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    if (nums_size <= 2) { return nums_size; }
    const isize len = nums_size;

    int* dp = calloc((size_t)(2 * NUMS_DIFF * len), sizeof(*dp));
    assert(dp != NULL);
    int* pos = &dp[0];
    int* neg = &dp[NUMS_DIFF * len];
    int res = 0;

    for (isize i = len - 1; i >= 0; i -= 1) {
        assert(nums[i] >= MIN_ALLOWED_NUM && nums[i] <= MAX_ALLOWED_NUM);
        const isize idx_i = i * NUMS_DIFF;
        for (isize j = len - 1; j > i; j -= 1) {
            const isize idx_j = j * NUMS_DIFF;
            const int diff = nums[i] - nums[j];
            const int* prev_ptr = diff < 0 ? &neg[idx_j + (-diff)] : &pos[idx_j + diff];
            int curr = max_int(2, 1 + *prev_ptr);
            int* curr_ptr = diff < 0 ? &neg[idx_i + (-diff)] : &pos[idx_i + diff];
            *curr_ptr = max_int(*curr_ptr, curr);
            res = max_int(res, curr);
        }
    }

/* cleanup: */
    free(dp);
    return res;
}
