long long minOperations(int* nums, int len)
{
    assert(nums != NULL && len >= 0);
    if (len <= 1) { return 0; }
    long long res = 0;

    for (int i = 1; i < len; i += 1) {
        if (nums[i - 1] >= nums[i]) {
            res += nums[i - 1] - nums[i];
        }
    }

    return res;
}
