int backtrack(const uint32_t i, const uint32_t n, const uint32_t seen, int* memo)
{
    if (i > n) {
        return 1;
    }

    if (memo[seen] != -1) {
        return memo[seen];
    } 

    int res = 0;
    for (uint32_t curr = 1; curr <= n; curr += 1) {
        const uint32_t mask = 1u << curr;
        if ((seen & mask) == 0 && (curr % i == 0 || i % curr == 0)) {
            res += backtrack(i + 1, n, seen | mask, memo);
        }
    }

    memo[seen] = res;
    return res;
}

int countArrangement(int n_i32)
{
    assert(n_i32 >= 1 && n_i32 <= 15);
    const uint32_t n = (uint32_t)n_i32;
    const size_t memo_len = 1u << (n + 1u);
    int* memo = malloc((size_t)memo_len * sizeof(*memo));
    assert(memo != NULL);
    for (size_t i = 0; i < memo_len; i += 1) { memo[i] = -1; }
    const uint32_t seen = 0;

    const int res = backtrack(1, n , seen, memo);
/* cleanup: */
    free(memo);
    return res;
}
