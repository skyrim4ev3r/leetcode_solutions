typedef ptrdiff_t isize;

int wiggleMaxLength(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size >= 0);
    if (nums_size <= 1) { return nums_size; }

    const isize len = nums_size;
    int cnt = 1;
    int dir = 0;

    for (isize i = 1; i < len; i += 1) {
        if (nums[i] > nums[i - 1] && dir != 1) {
            dir = 1;
            cnt += 1;
        }

        if (nums[i] < nums[i - 1] && dir != -1) {
            dir = -1;
            cnt += 1;
        }
    }

    return cnt;
}
