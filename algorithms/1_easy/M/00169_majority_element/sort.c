static int cmp_int(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*) a_ptr;
    const int b = *(int*) b_ptr;
    return (a < b) - (a > b);
}

int majorityElement(int* nums, int nums_size)
{
    const size_t len = (size_t) nums_size;
    qsort(nums, len, sizeof(*nums), cmp_int);

    int max_freq = 0;
    int max_freq_num = 0;
    int curr_freq = 0;
    int curr_num = 0;

    for (size_t i = 0; i < len; i += 1) {
        const int num = nums[i];
        if (curr_num == num) {
            curr_freq += 1;
        } else {
            curr_num = num;
            curr_freq = 1;
        }

        if (curr_freq > max_freq) {
            max_freq = curr_freq;
            max_freq_num = curr_num;
        }
    }

    return max_freq_num;
}
