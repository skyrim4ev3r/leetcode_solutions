int minElement(int* nums, int numsSize)
{
    const size_t len = numsSize;
    int res = INT_MAX;

    for (size_t i = 0; i < len; i += 1) {
        int sum = 0;
        int num = nums[i];

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        if (res > sum) {
            res = sum;
        }
    }

    return res;
}
