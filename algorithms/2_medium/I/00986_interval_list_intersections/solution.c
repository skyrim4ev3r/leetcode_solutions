typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** l1, int len1_int, int* cols1,
                           int** l2, int len2_int, int* cols2, 
                           int* return_len, int** return_cols)
{
    assert(l1 != NULL && l2 != NULL && cols1 != NULL && cols2 != NULL && len1_int >= 0 && len2_int >= 0 && return_len != NULL && return_cols != NULL);
    int** res = NULL;
    isize res_len = 0;
    isize res_cap = 0;
    const isize len1 = len1_int;
    const isize len2 = len2_int;
    isize idx1 = 0;
    isize idx2 = 0;

    while (idx1 < len1 && idx2 < len2) {
        const int lo = max_int(l1[idx1][0], l2[idx2][0]);
        const int hi = min_int(l1[idx1][1], l2[idx2][1]);

        if (lo <= hi)  {
            if (res_len == res_cap) {
                const isize new_cap = res_cap == 0 ? 4 : 2 * res_cap;
                res = realloc(res, (size_t)new_cap * sizeof(*res));
                assert(res != NULL);
                res_cap = new_cap;
            }
            int* data = malloc(2 * sizeof(*data));
            data[0] = lo;
            data[1] = hi;
            res[res_len] = data;
            res_len += 1; 
        }

        if (l1[idx1][1] == hi) {
            idx1 += 1;
        }

        if (l2[idx2][1] == hi) {
            idx2 += 1;
        }
    }

    assert(res_len <= INT_MAX);
    *return_len = res_len;
    *return_cols = malloc((size_t)res_len * sizeof(*return_cols));
    assert(*return_cols != NULL);
    for (isize i = 0; i < res_len; i += 1) { (*return_cols)[i] = 2; }

    return res;
}
