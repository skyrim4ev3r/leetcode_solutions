typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

int dfs(const char* w1, const isize i1, const isize len1, 
        const char* w2, const isize i2, const isize len2, int* memo)
{
    if (i1 == len1) {
        return (int)(len2 - i2);
    }

    if (i2 == len2) {
        return (int)(len1 - i1);
    }

    const isize memo_idx = i1 * len2 + i2;

    if (memo[memo_idx] != -1) {
        return memo[memo_idx];
    }

    int res = INT_MAX;

    if (w1[i1] == w2[i2]) {
        res = dfs(w1, i1 + 1, len1, w2, i2 + 1, len2, memo);
    } else {
        res = 1 + dfs(w1, i1 + 1, len1, w2, i2 + 1, len2, memo);
        res = min_int(res, 1 + dfs(w1, i1, len1, w2, i2 + 1, len2, memo));
        res = min_int(res, 1 + dfs(w1, i1 + 1, len1, w2, i2, len2, memo));
    };

    memo[memo_idx] = res;
    return res;
}

int minDistance(char* word1, char* word2)
{
    assert(word1 != NULL && word2 != NULL);
    const isize len1 = (isize)strlen(word1);
    const isize len2 = (isize)strlen(word2);
    const isize memo_len = len1 * len2;
    int* memo = malloc((size_t)memo_len * sizeof(*memo));
    assert(memo != NULL);
    for (isize i = 0; i < memo_len; i += 1) { memo[i] = -1; }
    const int res = dfs(word1, 0, len1, word2, 0, len2, memo);

/* cleanup: */
    free(memo);
    return res;
}
