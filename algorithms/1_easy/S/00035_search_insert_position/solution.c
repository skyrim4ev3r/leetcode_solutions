static size_t binary_search(int* nums, const size_t len, const int val)
{
    size_t left = 0;
    size_t right = len - 1;

    while (right < len && left <= right) {
        const size_t mid = left + (right - left) / 2;

        if (nums[mid] > val) {
            right = mid - 1;
        } else if (nums[mid] < val) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return left;
}

int searchInsert(int* nums, int numsSize, int target)
{
    return (int) binary_search(nums, numsSize, target);
}
