static inline int abs_int(const int a)
{
    return a < 0 ? -a : a;
}

static int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;
    return (a > b) - (a < b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getStrongest(int* arr, int arr_len, int k, int* return_size)
{
    assert(arr != NULL && return_size != NULL && arr_len >= 1 && k >= 1 && k <= arr_len);
    qsort(arr, (size_t)arr_len, sizeof(*arr), cmp);
    const int mid = (arr_len - 1) / 2;
    const int m = arr[mid];
    int* res = malloc((size_t)k * sizeof(*res));
    assert(res != NULL);
    *return_size = k;

    int lo = 0;
    int hi = arr_len - 1;
    int res_idx = 0;

    for (int step = 0; step < k; step += 1) {
        if (abs_int(arr[lo] - m) > abs_int(arr[hi] - m)) {
            res[res_idx] = arr[lo];
            res_idx += 1;
            lo += 1;
        } else {
            res[res_idx] = arr[hi];
            res_idx += 1;
            hi -= 1;
        }
    }

    return res;
}
