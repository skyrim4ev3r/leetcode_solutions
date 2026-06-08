static inline ptrdiff_t lower_bound(const int* nums, ptrdiff_t start, ptrdiff_t end, const int target)
{
    assert(start >= 0 && end >= start);
    while (start < end) {
        const ptrdiff_t mid = start + (end - start) / 2;

        if (nums[mid] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int lengthOfLIS(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    const ptrdiff_t len = nums_size;
    ptrdiff_t stack_len = 0;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        const int curr_num = nums[i];
        const ptrdiff_t lb = lower_bound(nums, 0, stack_len, curr_num);

        nums[lb] = curr_num;
        if (lb == stack_len) {
            stack_len += 1;
        }
    }

    return (int) stack_len;
}
