int countDigitOccurrences(int* nums, int nums_len, int digit)
{
    assert(nums != NULL && nums_len > 0);
    int freq  = 0;

    for (int i = 0; i < nums_len; i += 1) {
        int num = nums[i];
        while (num > 0) {
            if (num % 10 == digit) {
                freq += 1;
            }
            num /= 10;
        }
    }

    return freq;
}
