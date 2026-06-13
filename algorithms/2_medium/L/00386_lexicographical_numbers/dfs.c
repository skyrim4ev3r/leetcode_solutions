static void dfs(int* res, ptrdiff_t* res_idx, int curr, const int n)
{
    if (curr > n) {
        return;
    }

    res[*res_idx] = curr;
    *res_idx += 1;
    curr *= 10;

    for (int i = 0; i < 10; ++i) {
        dfs(res, res_idx, curr + i, n);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* lexicalOrder(int n, int* return_size)
{
    assert(n > 0 && return_size != NULL);
    *return_size = n;
    int* res = malloc((size_t)n * sizeof(res));
    assert(res != NULL);
    ptrdiff_t res_idx = 0;

    for (int i = 1; i < 10; ++i) {
        dfs(res, &res_idx, i, n);
    }

    return res;
}
