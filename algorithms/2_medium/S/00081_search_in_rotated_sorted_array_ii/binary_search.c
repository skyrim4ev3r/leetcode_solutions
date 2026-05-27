static inline size_t find_smallest_index(const int* nums, const size_t len)
{
    size_t left = 0;
    size_t right = len - 1;

    while (left < right) {
        const size_t mid = left + (right - left) / 2;

        if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
            left += 1;

            if (nums[left - 1] > nums[left]) {
                return left;
            }
        } else if (nums[mid] >= nums[left]) {
            left = mid + 1;

            if (nums[left - 1] > nums[left]) {
                return left;
            } 
        } else {
            right = mid - 1;

            if (nums[right] > nums[right + 1]) {
                return right + 1;
            }
        }
    }

    return left;
}

static bool binary_search(const int* nums, const size_t len, const int target)
{
    if (len == 0) {
        return false;
    }

    size_t left = 0;
    size_t right = len - 1;

    while (left <= right && right < len) {
        const size_t mid = left + (right - left) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

bool search(int* nums, int numsSize, int target)
{
    const size_t len = numsSize;
    const size_t min_index = find_smallest_index(nums, len);

    return binary_search(nums, min_index, target) ||
           binary_search(nums + min_index, len - min_index, target);
}