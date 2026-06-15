typedef ptrdiff_t isize;

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int dfs(const char* s, const isize len,const isize lo, const isize hi, int* memo)
{
    if (lo < 0 || hi >= len) {
        return 0;
    }

    const isize memo_idx = lo * len + hi;

    if (memo[memo_idx] != -1) {
        return memo[memo_idx];
    }

    int res = 0;
    if (s[lo] == s[hi]) {
        res = 2 + dfs(s, len, lo - 1, hi + 1, memo);
    } else {
        res = max_int(dfs(s, len, lo, hi + 1, memo), dfs(s, len, lo - 1, hi, memo));
    };

    memo[memo_idx] = res;
    return res;
}

int longestPalindromeSubseq(char* s)
{
    assert(s != NULL);
    const isize len = (isize)strlen(s);
    const isize memo_len = len * len;
    int* memo = malloc((size_t)memo_len * sizeof(*memo));
    assert(memo != NULL);
    for (isize i = 0; i < memo_len; i += 1) { memo[i] = -1; }
    int max_palindrom = 0;

    for (isize i = 0; i < len; i += 1) {
        max_palindrom = max_int(max_palindrom, 1 + dfs(s, len, i - 1, i + 1, memo));
        max_palindrom = max_int(max_palindrom, dfs(s, len, i, i + 1, memo));
    }

/* cleanup: */
    free(memo);
    return max_palindrom;
}
