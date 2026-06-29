/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int nums_len, int maximum_bit, int* return_size)
{
    assert(nums != NULL && nums_len > 0 && maximum_bit <= 20 && maximum_bit >= 0);
    const int mask = (1 << maximum_bit) - 1;
    int xor = 0;
    int* res = malloc((size_t)nums_len * sizeof(*res));
    assert(res != NULL);
    *return_size = nums_len;

    for (int i = 0; i < nums_len; i += 1) {
        xor ^= nums[i];
        res[i] = mask ^ xor;
    }

    int lo = 0;
    int hi = nums_len - 1;

    while (lo < hi) {
        const int temp = res[lo];
        res[lo] = res[hi];
        res[hi] = temp;

        lo += 1;
        hi -= 1;
    }

    return res;
}
