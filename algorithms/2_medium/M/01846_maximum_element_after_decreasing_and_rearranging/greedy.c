static int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

int maximumElementAfterDecrementingAndRearranging(int* arr, int arr_len)
{
    assert(arr != NULL && arr_len > 0);
    qsort(arr, (size_t)arr_len, sizeof(*arr), cmp);

    int curr = 0;
    for (int i = 0; i < arr_len; i += 1) {
        if (arr[i] > curr) {
            curr += 1;
        }
    }

    return curr;
}
