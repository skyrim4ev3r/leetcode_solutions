static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

long long maxTotalValue(int* nums, int nums_size, int k)
{
    const ptrdiff_t len = nums_size;
    assert(nums != NULL && len > 0);
    int max = INT_MIN;
    int min = INT_MAX;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        max = max_int(max, nums[i]);
        min = min_int(min, nums[i]);
    }

    return ((long long) max - (long long) min) * (long long) k;
}
