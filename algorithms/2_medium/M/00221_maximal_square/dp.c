static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maximalSquare(char** matrix, int matrix_size, int* matrix_col_size)
{
    assert(matrix != NULL && matrix_size > 0 && matrix_col_size[0] > 0);
    const ptrdiff_t rows = matrix_size;
    const ptrdiff_t cols = matrix_col_size[0];
    int* dp = malloc((size_t) (2 * (cols + 1)) * sizeof(*dp));
    assert(dp != NULL);
    memset(dp, 0, (size_t) (2 * (cols + 1)) * sizeof(*dp));
    int* curr = dp;
    int* next = &dp[cols];
    int max_side = 0;

    for (ptrdiff_t i = rows - 1; i >= 0 ; i -= 1) {
        for (ptrdiff_t j = cols - 1; j >= 0; j -= 1) {
            if (matrix[i][j] == '1') {
                curr[j] = 1 + min_int(next[j + 1], min_int(next[j], curr[j + 1]));
                max_side = max_int(max_side, curr[j]);
            }
        }

        int* temp = curr;
        curr = next;
        next = temp;
        memset(curr, 0, (size_t) (cols + 1) * sizeof(*curr));
    }

cleanup:
    free(dp);
    return max_side * max_side;
}
