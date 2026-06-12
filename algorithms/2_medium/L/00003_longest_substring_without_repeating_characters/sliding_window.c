#define MAP_LEN 256 // Cover all possible unsigned char values (0–255)

static inline ptrdiff_t max_isize(const ptrdiff_t a, ptrdiff_t b)
{
    return a > b ? a : b;
}

int lengthOfLongestSubstring(const char* s)
{
    assert(s != NULL);
    ptrdiff_t last_seen[MAP_LEN];
    memset(last_seen, -1, sizeof(last_seen));
    ptrdiff_t longest_substr = 0;
    ptrdiff_t lo = 0;

    for (ptrdiff_t hi = 0; s[hi] != '\0'; hi += 1) {
        const ptrdiff_t idx = (ptrdiff_t) (unsigned char) s[hi];
        lo = max_isize(lo, last_seen[idx] + 1);
        longest_substr = max_isize(longest_substr, hi - lo + 1);
        last_seen[idx] = hi;
    }

    return (int) longest_substr;
}
