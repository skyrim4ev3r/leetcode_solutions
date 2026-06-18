typedef ptrdiff_t isize;

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

struct slice_char {
    const char* ptr;
    isize len;
};

static int lcs(struct slice_char b1, struct slice_char b2)
{
    if (b1.len == 0 || b2.len == 0) {
        return 0;
    }

    if (b1.len < b2.len) {
        struct slice_char temp = b1;
        b1 = b2;
        b2 = temp;
    }

    const isize len1 = b1.len;
    const isize len2 = b2.len;
    int* dp = calloc(2 * ((size_t)len2 + 1), sizeof(*dp));
    int* curr = &dp[0];
    int* next = &dp[len2 + 1];

    for (isize idx1 = len1 - 1; idx1 >= 0; idx1 -= 1) {
        for (isize idx2 = len2 - 1; idx2 >= 0; idx2 -= 1) {
            if (b1.ptr[idx1] == b2.ptr[idx2]) {
                curr[idx2] = 1 + next[idx2 + 1];
            } else {
                curr[idx2] = max_int(curr[idx2 + 1], next[idx2]);
            }
        }

        int* temp = curr;
        curr = next;
        next = temp;
    }

    const int res = next[0];
/* cleanup: */
    free(dp);
    return res;
}

int minDistance(char* word1, char* word2)
{
    assert(word1 != NULL && word2 != NULL);
    const isize len1 = strlen(word1);
    const isize len2 = strlen(word2);

    const struct slice_char b1 = { ptr: word1, len: len1 };
    const struct slice_char b2 = { ptr: word2, len: len2 };

    return (int)(len1 + len2) - 2 * lcs(b1, b2);
}
