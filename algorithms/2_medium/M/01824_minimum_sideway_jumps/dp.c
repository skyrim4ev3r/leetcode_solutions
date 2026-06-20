#define INF 10000000

typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int* min_element(int* arr, isize len)
{
    if (arr == NULL || len <= 0) { return NULL; }

    int* min = &arr[0];

    for (isize i = 1; i < len; i += 1) {
        if (*min > arr[i]) {
            min = &arr[i];
        }
    }

    return min;
}

int minSideJumps(int* obstacles, int obstacles_size)
{
    assert(obstacles_size > 1 && obstacles[0] == 0);
    const isize len = obstacles_size;
    int dp[3] = {1, 0, 1};

    for (isize i = 1; i < len; i += 1) {
        const isize obs = obstacles[i];

        if (obs > 0) {
            dp[obs - 1] = INF;
        }

        const int min = *min_element(&dp[0], 3);

        for (isize i = 0; i < 3; i += 1) {
            if (i + 1 != obs) {
                dp[i] = min_int(dp[i], 1 + min);
            }
        }
    }

    return *min_element(&dp[0], 3);
}
