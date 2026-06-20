typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

struct pair {
    int i;
    int h;
};

static inline int clac_max(const struct pair p1, const struct pair p2)
{
    int i1 = p1.i, h1 = p1.h, i2 = p2.i, h2 = p2.h;

    if (h1 < h2) {
        const int diff = h2 - h1;
        h1 += diff;
        i1 += diff;
    } else {
        const int diff = h1 - h2;
        h2 += diff;
        i2 -= diff;
    }

    const int space_in_between = i2 - i1 - 1;

    return ((space_in_between + 1) / 2) + h1;
}

int cmp(const void* a_ptr, const void* b_ptr)
{
    const struct pair* a = a_ptr;
    const struct pair* b = b_ptr;
    return (a->i > b->i) - (a->i < b->i);
}

int maxBuilding(int n, int** restrictions, int restrictions_size, int* restrictions_col_size)
{
    assert(n >= 2 && n > restrictions_size && restrictions != NULL && restrictions_col_size != NULL);
    if (restrictions_size == 0) { return n - 1; }
    const isize restrictions_len = restrictions_size;
    struct pair* data = malloc((size_t)(restrictions_len + 2) * sizeof(*data));
    assert(data != NULL);

    isize data_idx = 0;
    data[data_idx] = (struct pair){ i: 1, h: 0 };
    data_idx += 1;
    for (isize i = 0; i < restrictions_len; i += 1) {
        data[data_idx] = (struct pair){ i: restrictions[i][0], h: restrictions[i][1]};
        data_idx += 1;
    }

    qsort(data, (size_t)data_idx, sizeof(*data), cmp);

    if (data[data_idx - 1].i != n) {
        data[data_idx] = (struct pair){ i: n, h: n - 1 };
        data_idx += 1;
    }

    const isize len = data_idx;

    for (isize i = 1; i < len; i += 1) {
        const int diff_i = data[i].i - data[i - 1].i;
        data[i].h = min_int(data[i].h, data[i - 1].h + diff_i);
    }

    for (isize i = len - 2; i >= 0; i -= 1) {
        const int diff_i = data[i + 1].i - data[i].i;
        data[i].h = min_int(data[i].h, data[i + 1].h + diff_i);
    }

    int max = 0;

    for (isize i = 1; i < len; i += 1) {
        max = max_int(max, clac_max(data[i - 1], data[i]));
    }
/* cleanup: */
    free(data);
    return max;
}
