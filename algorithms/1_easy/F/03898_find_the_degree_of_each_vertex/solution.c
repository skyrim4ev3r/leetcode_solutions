/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    *returnSize = matrixSize;
    const size_t n = matrixSize;
    int* res = (int*) malloc(n * sizeof(*res));

    for (size_t i = 0; i < n; i += 1) {
        int sum = 0;
        for (size_t j = 0; j < n; j += 1) {
            sum += matrix[i][j];
        }
        res[i] = sum;
    }

    return res;
}
