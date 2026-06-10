int cmp_int(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*) a_ptr;
    const int b = *(int*) b_ptr;

    return (a > b) - (a < b);
}

bool containsDuplicate(int* nums, int nums_size)
{
    const ptrdiff_t len = nums_size;
    assert(nums != NULL && len > 0);
    qsort(nums, (size_t) len, sizeof(*nums), cmp_int);

    for (ptrdiff_t i = 1; i < len; i += 1) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}
