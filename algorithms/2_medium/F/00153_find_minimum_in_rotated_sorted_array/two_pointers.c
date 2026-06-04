static inline int min_int(const int a, const int b)
{
    return a < b ? a: b;
}

int findMin(int* nums, int nums_size)
{
    ptrdiff_t left = 0;
    ptrdiff_t right = (ptrdiff_t) nums_size - 1;
    int min_val = INT_MAX;

    while (left <= right) {
        const ptrdiff_t mid = left + (right - left) / 2;

        if (nums[left] <= nums[mid]) {
            min_val = min_int(min_val, nums[left]);
            left = mid + 1;
        } else {
            min_val = min_int(min_val, nums[mid]);
            right = mid - 1;
        }
    }

    return min_val;
}
