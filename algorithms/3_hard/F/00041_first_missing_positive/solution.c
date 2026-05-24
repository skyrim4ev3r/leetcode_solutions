int firstMissingPositive(int* nums, int numsSize)
{
    const size_t len = numsSize;

    for (size_t i = 0; i < len; i += 1) {
        if (nums[i] <= 0) {
            nums[i] = INT_MAX;
        }
    }

    for (size_t i = 0; i < len; i += 1) {
        const size_t num_index = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
        if (num_index < len && nums[num_index] > 0) {
            nums[num_index] *= -1;
        }
    }

    for (size_t i = 0; i < len; i += 1) {
        if (nums[i] > 0) {
            return (int) (i + 1);
        }
    }

    return (int) len + 1;
}
