int singleNumber(int* nums, int numsSize)
{
    const size_t len = numsSize;
    int res = 0;

    for (size_t i = 0; i < len; i += 1) {
        res ^= nums[i];
    }

    return res;
}
