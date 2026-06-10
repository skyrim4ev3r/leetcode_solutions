int missingNumber(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    const ptrdiff_t len = nums_size;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        const ptrdiff_t num_as_index = nums[i] < 0 ? abs(nums[i]) - 1: nums[i];
        assert(num_as_index <= len);

        if (num_as_index != len) {
            nums[num_as_index] = -1 * nums[num_as_index] - 1;
        }
    }

    for (ptrdiff_t i = 0; i < len; i += 1) {
        if (nums[i] >= 0) {
            return (int) i;
        }

        i += 1;
    }

    return (int) len;
}
