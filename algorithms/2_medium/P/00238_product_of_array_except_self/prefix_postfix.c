/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int nums_size, int* return_size)
{
    *return_size = nums_size;
    ptrdiff_t len = nums_size;
    assert(nums != NULL && len >= 2);
    int* res = malloc((size_t) len * sizeof(*res));

    int prefix_product = 1;
    for (ptrdiff_t i = 0; i < len; i += 1) {
        res[i] = prefix_product;
        prefix_product *= nums[i];
    }

    int postfix_product = 1;
    for (ptrdiff_t i = len - 1; i >= 0; i -= 1) {
        res[i] *= postfix_product;
        postfix_product *= nums[i];
    }

    return res;
}
