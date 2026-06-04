int majorityElement(int* nums, int nums_size)
{
    const size_t len = (size_t) nums_size;
    int majority_candidate = 0;
    int count = 0;

    for (size_t i = 0; i < len; i += 1) {
        if (count == 0) {
            majority_candidate = nums[i];
            count = 1;
        } else if (majority_candidate == nums[i]) {
            count += 1;
        } else {
            count -= 1;
        }
    }

    return majority_candidate;
}
