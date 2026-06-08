static inline void reverse(int* arr, ptrdiff_t start, ptrdiff_t end)
{
    assert(start >= 0 && start <= end);
    while (start < end) {
        end -= 1;

        const int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start += 1;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int nums_size, int pivot, int* return_size)
{
    *return_size = nums_size;
    const ptrdiff_t len = nums_size;
    assert(len > 0);
    int* res = malloc((size_t) len * sizeof(*res));
    assert(res != NULL);
    ptrdiff_t lo = 0;
    ptrdiff_t hi = len - 1;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        if (nums[i] < pivot) {
            res[lo] = nums[i];
            lo += 1;
        } else if (nums[i] > pivot) {
            res[hi] = nums[i];
            hi -= 1;
        }
    }

    reverse(res, hi + 1, len);

     for (ptrdiff_t i = lo; i <= hi; i += 1) {
        res[i] = pivot;
    }

    return res;
}
