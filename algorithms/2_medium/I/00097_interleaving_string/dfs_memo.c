typedef ptrdiff_t isize;

struct slice_char {
    const char* ptr;
    isize len;
};

static bool are_equal_slice_char(const struct slice_char a, const struct slice_char b)
{
    if (a.len != b.len) {
        return false;
    }

    for (isize i = 0; i < a.len; i += 1) {
        if (a.ptr[i] != b.ptr[i]) {
            return false;
        }
    }

    return true;
}

static bool dfs(const struct slice_char b1, const isize b1_idx,
                const struct slice_char b2, const isize b2_idx,
                const struct slice_char b3, const isize b3_idx, bool* memo)
{
    if (b3_idx == b3.len) {
        return true;
    }

    const isize memo_idx = b1_idx * (b2.len + 1) + b2_idx;

    if (memo[memo_idx] == 0) {
        return false;
    }

    if (b1_idx < b1.len && b1.ptr[b1_idx] == b3.ptr[b3_idx]) {
        if (dfs(b1, b1_idx + 1, b2, b2_idx, b3, b3_idx + 1, memo)) {
            return true;
        }
    }

    if (b2_idx < b2.len && b2.ptr[b2_idx] == b3.ptr[b3_idx]) {
        if (dfs(b1, b1_idx, b2, b2_idx + 1, b3, b3_idx + 1, memo)) {
            return true;
        }
    }

    memo[memo_idx] = false;
    return false;
}

bool isInterleave(char* s1, char* s2, char* s3)
{
    struct slice_char b1 = { ptr: s1, len: (isize)strlen(s1) };
    struct slice_char b2 = { ptr: s2, len: (isize)strlen(s2) };
    struct slice_char b3 = { ptr: s3, len: (isize)strlen(s3) };

    if (b1.len + b2.len != b3.len) {
        return false;
    }

    if (b1.len == 0 || b2.len == 0) {
        return are_equal_slice_char(b3, b1) || are_equal_slice_char(b3, b2);
    }

    bool* memo = malloc((size_t)((b1.len + 1) * (b2.len + 1)) * sizeof(*memo));
    assert(memo != NULL);
    memset(memo, 1, (size_t)((b1.len + 1) * (b2.len + 1)) * sizeof(*memo));

    const bool res = dfs(b1, 0, b2, 0, b3, 0, memo);

/* cleanup: */
    free(memo);
    return res;
}
