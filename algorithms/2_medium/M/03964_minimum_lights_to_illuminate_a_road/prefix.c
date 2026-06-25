typedef ptrdiff_t isize;

static inline isize min_isize(const isize a, const isize b)
{
    return a < b ? a : b;
}

static inline isize max_isize(const isize a, const isize b)
{
    return a > b ? a : b;
}

int minLights(int* lights, int lights_size)
{
    assert(lights != NULL && lights_size >= 0);
    const isize n = lights_size;
    int* prefix = calloc((size_t)(n + 3), sizeof(*prefix));
    assert(prefix != NULL);

    for (isize i = 0; i < n; i += 1) {
        const int light = lights[i];
        if (light > 0) {
            const isize lo = max_isize(i - light, 0);
            const isize hi = min_isize(i + light + 1, n);
            prefix[lo] += 1;
            prefix[hi] -= 1;
        }
    }

    int sum = 0;
    int cnt_need = 0;
    for (isize i = 0; i < n; i += 1) {
        sum += prefix[i];
        if (sum == 0) {
            sum += 1;
            cnt_need += 1;
            prefix[i + 3] -= 1;
        }
    }

/* cleanup: */
    free(prefix);
    return cnt_need;
}
