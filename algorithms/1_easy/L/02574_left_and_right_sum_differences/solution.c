static inline int abs_int(const int a)
{
    return a < 0 ? -a : a;
}

static inline int reduce_int(const int* nums, const size_t len, int sum_start)
{
    for (size_t i = 0; i < len; i += 1) {
        sum_start += nums[i];
    }

    return sum_start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int nums_size, int* return_size)
{
    *return_size = nums_size;
    const size_t len = (size_t) nums_size;
    int* res = malloc(len * sizeof(*res));
    int sum_to_right = reduce_int(nums, len, 0);
    int sum_to_left = 0;

    for (size_t i = 0; i < len; i += 1)  {
        sum_to_right -= nums[i];
        res[i] = abs_int(sum_to_right - sum_to_left);
        sum_to_left += nums[i];
    }

    return res;
}
