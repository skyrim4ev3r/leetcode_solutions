typedef ptrdiff_t isize;

struct slice_char {
    const char* ptr;
    const isize len;
};

static int dfs(struct slice_char b1, const isize idx1,
               struct slice_char b2, const isize idx2, int* memo) 
{
    if (idx2 == b2.len) { return 1; }
    if (idx1 == b1.len) { return 0; }

    const isize remain1 = b1.len - idx1;
    const isize remain2 = b2.len - idx2;
    if (remain1 < remain2) { return 0; }

    const isize memo_idx = idx1 * b2.len + idx2;
    if (memo[memo_idx] != -1) { return memo[memo_idx]; }

    int res = 0;
    if (b1.ptr[idx1] == b2.ptr[idx2]) {
        res += dfs(b1, idx1 + 1, b2, idx2 + 1, memo);
    }

    res += dfs(b1, idx1 + 1, b2, idx2, memo);
    memo[memo_idx] = res;
    return res;
}

int numDistinct(char* s, char* t)
{
    assert(s != NULL && t != NULL);
    struct slice_char b1 = { ptr: s, len: strlen(s) };
    struct slice_char b2 = { ptr: t, len: strlen(t) };
    if (b1.len < b2.len) {
        return 0;
    }

    const isize memo_len = b1.len * b2.len;
    int* memo = malloc((size_t)memo_len * sizeof(*memo));
    assert(memo != NULL);
    for (isize i = 0; i < memo_len; i += 1) { 
        memo[i] = -1;
    }

    const int res =  dfs(b1, 0, b2, 0, memo);

/* cleanup: */
    free(memo);
    return res;
}
