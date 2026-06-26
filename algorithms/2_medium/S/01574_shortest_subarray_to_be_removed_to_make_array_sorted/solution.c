typedef ptrdiff_t isize;

static inline isize custom_longest(const int* sorted_prefix, const isize sorted_prefix_len, 
                                   const int* sorted_suffix, const isize sorted_suffix_len)
{
    int* sub = malloc((size_t)sorted_prefix_len * sizeof(*sub));
    assert(sub != NULL);
    for (isize i = 0; i < sorted_prefix_len; i += 1) { sub[i] = sorted_prefix[i]; }
    const isize sub_len = sorted_prefix_len;
    isize res = sub_len;

    for (isize i = 0; i < sorted_suffix_len; i += 1) {
        const int a = sorted_suffix[i];
        isize hi = sub_len - 1;
        isize lo = 0;

        while (lo <= hi) {
            const isize mid = lo + (hi - lo) / 2;

            if (sub[mid] <= a) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (lo == sub_len) {
            // all remaining elems are sorted and can be added to current sub
            res = (sorted_suffix_len - i) + sub_len;
            goto cleanup;
        } else {
            sub[lo] = a;
        }
    }

cleanup:
    free(sub);
    return res;
}

int findLengthOfShortestSubarray(int* arr, int arr_size)
{
    assert(arr != NULL && arr_size >= 0);
    const isize len = arr_size;
    if (len <= 1) { return 0; }
    isize hi = len - 1;
    isize lo = 0;

    while (hi > 0 && arr[hi - 1] <= arr[hi]) {
        hi -= 1;
    }

    if (hi == 0) {
        return 0;
    }

    while (arr[lo] <= arr[lo + 1]) {
        lo += 1;
    }

    const int* sorted_prefix = &arr[0];
    const isize sorted_prefix_len = lo + 1;
    const int* sorted_suffix = &arr[hi];
    const isize sorted_suffix_len = len - hi;

    const isize longest = custom_longest(sorted_prefix, sorted_prefix_len,
                                       sorted_suffix, sorted_suffix_len);
    return (int)(len - longest);
}
