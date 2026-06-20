typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

int countSquares(int** matrix, int matrix_size, int* matrix_col_size)
{
    assert(matrix != NULL && matrix_size > 0 && matrix_col_size != NULL && matrix_col_size[0] > 0);
    const isize rows = matrix_size;
    const isize cols = matrix_col_size[0];
    const isize dp_rows = rows + 1;
    const isize dp_cols = cols + 1;
    int* dp = calloc((size_t)(dp_rows * dp_cols), sizeof(*dp));
    assert(dp != NULL);
    int count = 0 ;

    for (isize i = rows - 1; i >= 0; i -= 1) {
        for (isize j = cols - 1; j >= 0; j -= 1) {
            if (matrix[i][j] == 1) {
                const int r = dp[i * dp_cols + j + 1];
                const int d = dp[(i + 1) * dp_cols + j];
                const int rd = dp[(i + 1) * dp_cols + j + 1];

                dp[i * dp_cols + j] = 1 + min_int(r, min_int(d, rd));
                count += dp[i * dp_cols + j];
            }
        }
    }

/* cleanup: */
    free(dp);
    return count;
}
