#define MAX_ALLOWED_PILE 10000

typedef ptrdiff_t isize;

struct min_max {
    const int* min;
    const int* max;
};

static inline struct min_max max_element(const int* arr, isize len)
{
    if (arr == NULL || len == 0) { (struct min_max){ min: NULL, max: NULL }; }
    const int* max = &arr[0];
    const int* min = &arr[0];

    for (isize i = 1; i < len; i += 1) {
        if (arr[i] > *max) {
            max = &arr[i];
        }

        if (arr[i] < *min) {
            min = &arr[i];
        }
    }

    struct min_max res = { min: min, max: max };
    return res;
}

int maxCoins(int* piles, int len)
{
    assert(piles != NULL && len > 0 && len % 3 == 0);
    const struct min_max min_max = max_element(piles, len);
    const int min = *min_max.min;
    const int max = *min_max.max;
    assert(max <= MAX_ALLOWED_PILE && min > 0);
    int* freqs = calloc((size_t)(max - min + 1), sizeof(*freqs));
    assert(freqs != NULL);

    for (int i = 0; i < len; i += 1) {
        const int p = piles[i];
        freqs[p - min] += 1;
    }

    const int target_cnt = (len / 3) * 2;
    int curr_idx = max - min;
    int amount = 0;
    for (int cnt = 0; cnt < target_cnt; cnt += 1) {
        while (freqs[curr_idx] == 0) {
            curr_idx -= 1;
        }
        freqs[curr_idx] -= 1;
        if ((cnt & 1) == 1) {
            amount += curr_idx + min;
        }
    }

    return amount;
}
