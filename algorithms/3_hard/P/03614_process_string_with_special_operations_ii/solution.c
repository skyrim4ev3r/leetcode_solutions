static inline long long max_long_long(const long long a, const long long b)
{
    return a > b ? a : b;
}

struct pair {
    long long res_len;
    ptrdiff_t s_len;
};

static inline struct pair calc_final_res_len(const char* s)
{
    long long res_len = 0;
    ptrdiff_t i = 0;

    for (i = 0; s[i] != '\0'; i += 1) {
        const char ch = s[i];

        if (ch == '#') {
            res_len *= 2;
        } else if (ch >= 'a' && ch  <= 'z') {
            res_len += 1;
        } else if (ch == '*') {
            res_len = max_long_long(0, res_len - 1);
        }
    }

    const struct pair pair = { res_len: res_len, s_len: i };
    return pair;
}

char processStr(char* s, long long k)
{
    assert(s != NULL && k >= 0);
    const struct pair data = calc_final_res_len(s);
    long long res_len = data.res_len;
    if (res_len <= k) {
        return '.';
    }

    for (ptrdiff_t i = data.s_len - 1; i >= 0; i -= 1) {
        const char ch = s[i];

        if (ch == '#') {
            res_len /= 2;
            if (k >= res_len) {
                k -= res_len;
            }
        } else if (ch >= 'a' && ch  <= 'z') {
            res_len -= 1;
            if (res_len == k) {
                return ch;
            }
        } else if (ch == '*') {
            res_len += 1;
        } else if (ch == '%') {
            k = res_len - k - 1;
        } else {
            fprintf(stderr, "invalid input");
            abort();
        }
    }

    return '.';
}
