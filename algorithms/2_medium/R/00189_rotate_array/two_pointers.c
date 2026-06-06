static void rev(int* nums, size_t left, const size_t right_exclude)
{
    if (right_exclude <= left) {
        return;
    }

    size_t right = right_exclude - 1;

    while (left < right) {
        const int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        left += 1;
        right -= 1;
    }
}

void rotate(int* nums, int nums_size, int k)
{
    const size_t len = nums_size;
    const size_t split_point = len - ((size_t) k) % len;

    rev(nums, 0, split_point);
    rev(nums, split_point, len);
    rev(nums, 0, len);
}
