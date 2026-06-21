typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maxIceCream(int* costs, int costs_size, int coins)
{
    assert(costs != NULL && costs_size > 0 && coins > 0);
    const isize len = costs_size;
    int min = INT_MAX;
    int max = INT_MIN;

    for (isize i = 0; i < len; i += 1) {
        const int cost = costs[i];
        min = min_int(min, cost);
        max = max_int(max, cost);
    }

    assert(min > 0 && max > 0);
    const isize table_len = max - min + 1;
    int* table = calloc((size_t)table_len, sizeof(*table));
    assert(table != NULL);

    for (isize i = 0; i < len; i += 1) {
        table[costs[i] - min] += 1;
    }

    int cnt = 0;
    for (isize i = 0; i < table_len; i += 1) {
        const int freq = table[i];

        if (freq > 0) {
            const int val = (int)i + min;
            const int cnt_to_add = min_int(coins / val, freq);
            cnt += cnt_to_add;
            coins -= cnt_to_add * val;

            if (cnt_to_add < freq) {
                break;
            }
        }
    }

/* cleanup: */
    free(table);
    return cnt;
}
