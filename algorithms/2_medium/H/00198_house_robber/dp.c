static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int nums_size)
{
    const size_t len = nums_size;
    int curr = 0;
    int prev = 0;
    int prev_prev = 0;

    for (size_t i = 0; i < len; i += 1) {
        const int next = nums[i] + max_int(prev, prev_prev);
        prev_prev = prev;
        prev = curr;
        curr = next;
    }

    return max_int(curr, prev);
}
