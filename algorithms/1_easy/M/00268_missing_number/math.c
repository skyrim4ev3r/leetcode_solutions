int missingNumber(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    const ptrdiff_t len = nums_size;
    int sum = 0;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        sum += nums[i];
    }

    assert((len * (len + 1)) / 2 <= INT_MAX);
    const int target_sum = (int) ((len * (len + 1)) / 2);
    return target_sum - sum;
}
