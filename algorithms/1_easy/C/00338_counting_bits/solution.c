/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* return_size)
{
    assert(return_size != NULL && n >= 0 && n != INT_MAX);
    *return_size = n + 1;
    int* res = malloc((size_t)(n + 1) * sizeof(*res));
    res[0] = 0;

    for (int i = 1; i <= n; i += 1) {
        res[i] = res[i >> 1] + (i & 1);
    }

    return res;
}
