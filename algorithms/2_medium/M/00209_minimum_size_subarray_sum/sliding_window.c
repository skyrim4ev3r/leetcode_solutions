static inline size_t min_usize(const size_t a, const size_t b)
{
    return a < b ? a : b;
}

int minSubArrayLen(int target, int* nums, int nums_size)
{
    assert(nums != NULL);
    assert(nums_size > 0);
    assert(target > 0);

    const size_t len = nums_size;
    size_t left = 0;
    int curr_sum = 0;
    size_t min_width = len + 1;

    for (size_t right = 0; right < len; right += 1) {
        assert(nums[right] > 0);
        assert(INT_MAX - nums[right] >= curr_sum);
        curr_sum += nums[right];

        while (curr_sum >= target) {
            min_width = min_usize(min_width, right - left + 1);
            curr_sum -= nums[left];
            left += 1;
        }
    }

    return (int) (min_width == len + 1 ? 0 : min_width);
}
