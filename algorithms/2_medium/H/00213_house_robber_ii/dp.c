static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static inline int rob_helper(const int* nums, const size_t start, const size_t end)
{
    int prev_prev = 0;
    int prev = 0;
    int curr = 0;

    for (size_t i = start; i < end; i += 1) {
        assert(nums[i] >= 0);
        const int next = nums[i] + max_int(prev, prev_prev);
        prev_prev = prev;
        prev = curr;
        curr = next;
    }

    return max_int(curr, prev);
}

int rob(int* nums, int nums_size)
{
    const size_t len = (size_t) nums_size;
    assert(len > 0);

    if (len == 1) {
        assert(nums[0] >= 0);
        return nums[0];
    }

    const int max_dp1 = rob_helper(nums, 0, len - 1);
    const int max_dp2 = rob_helper(nums, 1, len);

    return max_int(max_dp1, max_dp2);
}
