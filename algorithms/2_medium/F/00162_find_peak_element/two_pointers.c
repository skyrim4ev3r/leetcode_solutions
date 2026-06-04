int findPeakElement(int* nums, int nums_size)
{
    size_t right = (size_t) nums_size - 1;
    size_t left = 0;

    while (left < right) {
        const size_t mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return (int) left;
}
