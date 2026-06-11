static inline int abs_int(const int a)
{
    assert(a != INT_MIN);
    return a < 0 ? -a : a;
}

int findDuplicate(int* nums, int nums_size)
{
    assert(nums != NULL && nums_size > 0);
    const ptrdiff_t len = nums_size;

    for (ptrdiff_t i = 0; i < len ; i += 1) {
        assert(abs_int(nums[i]) - 1 >= 0 && abs_int(nums[i]) - 1 < len);
        if (nums[abs_int(nums[i]) - 1] > 0) {
            nums[abs_int(nums[i]) - 1] *= -1;
        } else {
            for (ptrdiff_t j = 0; j < i; j += 1) {
                nums[abs_int(nums[j]) - 1] *= -1;
            }

            return nums[i];
        }
    }

    fprintf(stderr, "Error: no duplicate found (invalid input or corrupted array)\n");
    abort();
}
