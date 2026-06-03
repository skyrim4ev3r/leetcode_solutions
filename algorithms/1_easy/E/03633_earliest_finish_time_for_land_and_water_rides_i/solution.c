static inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

static inline int min(const int a, const int b)
{
    return a < b ? a : b;
}

static int helper(const int* a_start_time, const int* a_duration, const size_t a_len,
                  const int* b_start_time, const int* b_duration, const size_t b_len)
{
    int min_a_end = INT_MAX;
    for (size_t i = 0; i < a_len; i += 1) {
        min_a_end = min(min_a_end, a_start_time[i] + a_duration[i]);
    }

    int res = INT_MAX;
    for (size_t i = 0; i < b_len; i += 1) {
        const int start_b = max(min_a_end, b_start_time[i]);
        const int end_b = start_b + b_duration[i];

        res = min(res, end_b);
    }

    return res;
}

int earliestFinishTime(int* land_start_time, int land_start_time_size, int* land_duration, int land_duration_size, 
                       int* water_start_time, int water_start_time_size, int* water_duration, int water_duration_size)
{
    const int land_first = helper(land_start_time, land_duration, (size_t) land_start_time_size, 
                                  water_start_time, water_duration, (size_t) water_start_time_size);
    const int water_first = helper(water_start_time, water_duration, (size_t) water_start_time_size,
                                   land_start_time, land_duration, (size_t) land_start_time_size);

    return min(land_first, water_first);
}
