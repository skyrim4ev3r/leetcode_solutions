
int countMajoritySubarrays(int* nums, int nums_size, int target)
{
    assert(nums != NULL && nums_size >= 0);
    int count = 0;

    for (int i = 0; i < nums_size; i += 1) {
        int freq = 0;
        for (int j = i; j < nums_size; j += 1) {
            if (nums[j] == target) {
                freq += 1;
            }

            if (freq > (j - i + 1) / 2) {
                count += 1;
            }
        }
    }

    return count;
}
