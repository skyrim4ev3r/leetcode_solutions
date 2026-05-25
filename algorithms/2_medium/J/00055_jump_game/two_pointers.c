bool canJump(int* nums, int numsSize)
{
    const size_t len = numsSize;
    size_t right = 0;
    size_t left = 0;

    while (right + 1 < len) {
        size_t new_right = 0;

        while (left <= right) {
            if (new_right < left + nums[left]) {
                new_right = left + nums[left];
            }
            left += 1;
        }

        if (new_right <= right) {
            return false;
        }

        right = new_right;
    }

    return true;
}
