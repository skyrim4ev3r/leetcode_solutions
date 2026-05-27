static inline int binomial_coefficient(int n, int k)
{
    if (k > n) { return 0; }
    if (k == 0 || k == n) { return 1; }
    int64_t res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return (int) res;
}

static void backtrack(int** res, size_t* res_idx, int* curr_vec, const size_t curr_vec_idx,
                      const int start_val, const int n, const int k)
{
    if (curr_vec_idx == (size_t) k) {
        int* arr = (int*) malloc(curr_vec_idx * sizeof(int));
        for (size_t i = 0; i < curr_vec_idx; i += 1) {
            arr[i] = curr_vec[i];
        }
        res[*res_idx] = arr;
        *res_idx += 1;
        return;
    }

    const int end_val = n - (k - (int) curr_vec_idx) + 1;
    for (int i = start_val; i <= end_val; i += 1) {
        curr_vec[curr_vec_idx] = i;
        backtrack(res, res_idx, curr_vec, curr_vec_idx + 1, i + 1, n, k);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    size_t res_len = binomial_coefficient(n, k);
    *returnSize = (int) res_len;
    int* col_info = (int*) malloc(res_len * sizeof(int));
    for (size_t i = 0; i < res_len; i += 1) {
        col_info[i] = k;
    }
    *returnColumnSizes = col_info;
    int** res = (int**) malloc(res_len * sizeof(int*));
    size_t res_idx = 0;
    int* curr_vec = (int*) malloc((size_t) k * sizeof(int));
    backtrack(res, &res_idx, curr_vec, 0, 1, n, k);
    free(curr_vec);

    return res;
}
