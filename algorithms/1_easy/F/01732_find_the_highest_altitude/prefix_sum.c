typedef ptrdiff_t isize;

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int largestAltitude(int* gain, int gain_size)
{
    assert(gain != NULL && gain_size > 0);
    const isize len = gain_size;
    int sum = 0;
    int max_g = 0;

    for (isize i = 0; i < len; i += 1) {
        sum += gain[i];
        max_g = max_int(max_g, sum);
    }

    return max_g;
}
