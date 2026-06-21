typedef ptrdiff_t isize;

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maximumSum(int* arr, int arr_size)
{
    assert(arr != NULL && arr_size > 0);
    const isize len = arr_size;
    int keep = arr[0];
    int del = 0;
    int res = arr[0];

    for (isize i = 1; i < len; i += 1) {
        const int a = arr[i];
        const int new_keep = max_int(a, keep + a);
        const int new_del = max_int(keep, del +  a);
        del = new_del;
        keep = new_keep;
        res = max_int(res, max_int(del, new_keep));
    }

    return res;
}
