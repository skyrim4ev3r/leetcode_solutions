int maxSubArray(int* nums, int numsSize)
{
    const size_t len = numsSize;
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for (size_t i = 0; i < len; i += 1) {
        curr_sum += nums[i];

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }

        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }

    return max_sum;
}
