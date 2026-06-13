#define DIRS_ROWS 4

const ptrdiff_t DIRECTIONS[DIRS_ROWS][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int dfs(const int** matrix, int* memo, const ptrdiff_t i, const ptrdiff_t j,
               const ptrdiff_t rows, const ptrdiff_t cols)
{
    if (memo[i * cols + j] != -1) {
        return memo[i * cols + j];
    }

    const int cell_val = matrix[i][j];
    int curr = 1;

    for (ptrdiff_t dir_idx = 0; dir_idx < DIRS_ROWS; dir_idx += 1) {
        const ptrdiff_t ni = i + DIRECTIONS[dir_idx][0];
        const ptrdiff_t nj = j + DIRECTIONS[dir_idx][1];
        if (ni < 0 || nj < 0 || ni >= rows || nj >= cols || matrix[ni][nj] <= cell_val) {
            continue;
        }
        curr = max_int(curr, 1 + dfs(matrix, memo, ni, nj, rows, cols));
    }

    memo[i * cols + j] = curr;
    return curr;
}

int longestIncreasingPath(int** matrix, int matrix_size, int* matrix_col_size)
{
    assert(matrix != NULL && matrix_size > 0 && matrix_col_size != NULL && matrix_col_size[0] > 0);
    const ptrdiff_t rows = matrix_size;
    const ptrdiff_t cols = matrix_col_size[0];
    int* memo = malloc((size_t)(rows * cols) * sizeof(*memo));
    assert(memo != NULL);
    for (ptrdiff_t i = 0; i < rows; ++i) {
        for (ptrdiff_t j = 0; j < cols; ++j) {
            memo[i * cols + j] = -1;
        }
    } 
    int max = 0;

    for (ptrdiff_t i = 0; i < rows; ++i) {
        for (ptrdiff_t j = 0; j < cols; ++j) {
            max = max_int(max, dfs((const int**)matrix, memo, i, j, rows, cols));
        }
    }

/* cleanup: */
    free(memo);
    return max;
}
