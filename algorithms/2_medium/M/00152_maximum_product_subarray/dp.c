static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

int maxProduct(int* nums, int numsSize)
{
    const size_t len = numsSize;
    int prev_max = 1;
    int prev_min = 1;
    int max_prod = INT_MIN;

    for (size_t i = 0; i < len; i += 1) {
        const int num = nums[i];
        const int curr_min = min_int(num, min_int(num * prev_min, num * prev_max));
        const int curr_max = max_int(num, max_int(num * prev_min, num * prev_max));

        max_prod = max_int(max_prod, curr_max);
        prev_max = curr_max;
        prev_min = curr_min;
    }

    return max_prod;
}
