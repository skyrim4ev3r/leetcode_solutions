bool increasingTriplet(int* nums, int nums_size)
{
    assert(nums != NULL);
    const ptrdiff_t len = nums_size;
    int mid_val = INT_MAX;
    int min_val = INT_MAX;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        const int curr_val = nums[i];

        if (curr_val > mid_val) {
            return true;
        }

        if (curr_val < min_val) {
            min_val = curr_val;
        } else if (curr_val > min_val && curr_val < mid_val) {
            mid_val = curr_val;
        }
    }

    return false;
}
