static size_t lower_bound(int* nums, const size_t len, const int val)
{
    size_t left = 0;
    size_t right = len - 1;

    while (right < len && left <= right) {
        const size_t mid = left + (right - left) / 2;

        if (nums[mid] >= val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* res = (int *) malloc(2 * sizeof(int));
    *returnSize = 2;
    const size_t len = numsSize;
    const size_t lb = lower_bound(nums, len, target);

    if (lb == len || nums[lb] != target) {
        res[0] = -1;
        res[1] = -1;
        return res;
    }

    const size_t ub = lower_bound(nums, len, target + 1) - 1;
    res[0] = (int) lb;
    res[1] = (int) ub;
    return res;
}
