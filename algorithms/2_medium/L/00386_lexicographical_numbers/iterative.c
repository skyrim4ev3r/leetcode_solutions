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
    int curr = 1;

    for (int i = 0; i < n; i += 1) {
        res[res_idx] = curr;
        res_idx += 1;

        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            while (curr % 10 == 9 || curr + 1 > n) {
                curr /= 10;
            }

            curr += 1;
        }
    }

    return res;
}
