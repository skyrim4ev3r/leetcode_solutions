int jump(int* nums, int numsSize) {
    const size_t len = numsSize;
    size_t right = 0;
    size_t left = 0;
    int steps = 0;

    while (right + 1 < len) {
        size_t new_right = 0;
        while (left <= right) {
            if (new_right <  left + nums[left]) {
                new_right = left + nums[left];
            }
            left += 1;
        }
        // If new_right <= right there is no progress — indicates invalid input.
        right = new_right;
        steps += 1;
    }

    return steps;
}
