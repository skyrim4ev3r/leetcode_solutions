static inline int* vec_clone(int* vec, const size_t len)
{
    int *temp = (int*) malloc(len * sizeof(*temp));
    for (size_t i = 0; i < len; i += 1) {
        temp[i] = vec[i];
    }
    return temp;
} 

static void backtrack(const int* nums, const size_t nums_len, const size_t nums_idx, int** res,
                      int* res_col_infos, size_t* res_len, int* curr_vec, size_t *curr_vec_len)
{
    if (nums_idx == nums_len) {
        res[*res_len] = vec_clone(curr_vec, *curr_vec_len);
        res_col_infos[*res_len] = (int) *curr_vec_len;
        *res_len += 1;
        return;
    }

    backtrack(nums, nums_len, nums_idx + 1, res, res_col_infos, res_len, curr_vec, curr_vec_len);

    curr_vec[*curr_vec_len] = nums[nums_idx];
    *curr_vec_len += 1;
    backtrack(nums, nums_len, nums_idx + 1, res, res_col_infos, res_len, curr_vec, curr_vec_len);
    *curr_vec_len -= 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    const size_t nums_len = (size_t) numsSize;
    const size_t nums_idx = 0;

    const size_t res_capacity = 1u << numsSize;
    int* res_col_infos = (int*) malloc(res_capacity * sizeof(*res_col_infos));
    int** res = (int**) malloc(res_capacity * sizeof(*res));
    size_t res_len = 0;
    *returnSize = (int) res_capacity;

    const size_t curr_vec_capacity = nums_len;
    int* curr_vec = (int*) malloc(curr_vec_capacity * sizeof(*curr_vec));
    size_t curr_vec_len = 0;

    backtrack(nums, nums_len, nums_idx, res, res_col_infos, &res_len, curr_vec, &curr_vec_len);

    *returnColumnSizes = res_col_infos;

cleanup:
    free(curr_vec);

    return res;
}