static inline size_t fact(size_t n)
{
    size_t r = 1;
    for (size_t i = 2; i <= n; i += 1) {
        r *= i;
    }
    return r;
}

void backtrack(int** res, const size_t rows, const size_t cols, size_t* res_push_index,
               int* temp, const size_t temp_index, bool* seen, int* nums)
{
    if (temp_index == cols) {
        res[*res_push_index] = (int*) malloc(cols * sizeof(int));
        int* curr_row = res[*res_push_index];
        for (size_t idx = 0; idx < cols; idx += 1) {
            curr_row[idx] = temp[idx];
        }
        *res_push_index = *res_push_index + 1;
        return;
    }

    for (size_t idx = 0; idx < cols; idx += 1) {
        if (!seen[idx]) {
            seen[idx] = true;
            temp[temp_index] = nums[idx];
            backtrack(res, rows, cols, res_push_index,
                      temp, temp_index + 1, seen, nums);
            seen[idx] = false;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    const size_t cols = numsSize;
    const size_t rows = fact(cols);
    int** res = (int**) malloc(rows * sizeof(int*));
    *returnColumnSizes = (int*) malloc(rows * sizeof(int));
    int* temp = (int*) malloc(cols * sizeof(int));
    bool* seen = (bool*) malloc(cols * sizeof(bool));
    memset(seen, 0, cols);
    *returnSize = rows;
    for (size_t i = 0; i < rows; ++i) {
        (*returnColumnSizes)[i] = cols;
    }
    size_t res_push_index = 0;
    backtrack(res, rows, cols, &res_push_index, temp, 0, seen, nums);
    free(seen);
    free(temp);
    return res;
}
