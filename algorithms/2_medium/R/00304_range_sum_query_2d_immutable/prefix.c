// (MAX_ACCEPTED_COLS + 1) * (MAX_ACCEPTED_COLS + 1) should be fit in ptrdiff_t
#define MAX_ACCEPTED_COLS 200
#define MAX_ACCEPTED_ROWS 200

typedef struct {
    int* prefix;
    ptrdiff_t rows;
    ptrdiff_t cols;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrix_size, int* matrix_col_size)
{
    assert(matrix != NULL && matrix_col_size != NULL && matrix_size > 0 && matrix_col_size[0] > 0 &&
           matrix_size <= MAX_ACCEPTED_ROWS && matrix_col_size[0] <= MAX_ACCEPTED_COLS);
    const ptrdiff_t rows = (ptrdiff_t)matrix_size + 1;
    const ptrdiff_t cols = (ptrdiff_t)matrix_col_size[0] + 1;
    int* prefix = malloc((size_t)(rows * cols) * sizeof(*prefix));
    assert(prefix != NULL);
    for (ptrdiff_t i = 0; i < rows; i += 1) { prefix[i * cols] = 0; }
    for (ptrdiff_t j = 0; j < cols; j += 1) { prefix[j] = 0; }

    for (ptrdiff_t i = 1; i < rows; i += 1) {
        assert(matrix[i - 1] != NULL && matrix_col_size[i - 1] + 1 == cols);
        for (ptrdiff_t j = 1; j < cols; j += 1) {
            const ptrdiff_t prefix_idx = (i * cols + j);
            const ptrdiff_t prefix_idx_up = (i - 1) * cols + j;
            const ptrdiff_t prefix_idx_left = i * cols + j - 1;
            const ptrdiff_t prefix_idx_upleft = (i - 1) * cols + j - 1;

            prefix[prefix_idx] = matrix[i - 1][j - 1] + 
                                 prefix[prefix_idx_up] +
                                 prefix[prefix_idx_left] -
                                 prefix[prefix_idx_upleft];
        }
    }

    NumMatrix* res = malloc(sizeof(*res));
    assert(res != NULL);
    res->prefix = prefix;
    res->rows = rows;
    res->cols = cols;

    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    assert(obj != NULL && row1 >= 0 && col1 >= 0 && row2 >=0 && col2 >= 0 &&
           row1 <= row2 && col1 <= col2 &&
           row2 < obj->rows - 1 && col2 < obj->cols - 1 );

    const ptrdiff_t upleft = row1 * obj->cols + col1;
    const ptrdiff_t up = row1 * obj->cols + (col2 + 1);
    const ptrdiff_t left = (row2 + 1) * obj->cols + col1;
    const ptrdiff_t downright = (row2 + 1) * obj->cols + (col2 + 1);

    return obj->prefix[downright] +
           obj->prefix[upleft] -
           obj->prefix[up] -
           obj->prefix[left] ;
}

void numMatrixFree(NumMatrix* obj)
{
    if(obj == NULL) { return; }
    free(obj->prefix);
    obj->prefix = NULL;
    obj->rows = 0;
    obj->cols = 0;
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
