typedef ptrdiff_t isize;

static inline isize max_isize(const isize a, const isize b)
{
    return a > b ? a : b;
}

static inline void reverse(char* s, isize start, isize end)
{
    while (start < end) {
        end -= 1;

        const char temp = s[end];
        s[end] = s[start];
        s[start] = temp;

        start += 1;
    }
}

static inline isize peak_result_len(const char* s)
{
    isize curr_res_len = 0;
    isize peak_len = 0;

    for (isize i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == '#') {
            curr_res_len *= 2;
        } else if (s[i] >= 'a' && s[i]  <= 'z') {
            curr_res_len += 1;
        } else if (s[i] == '*') {
            curr_res_len = max_isize(0, curr_res_len - 1);
        }

        peak_len = max_isize(peak_len, curr_res_len);
    }

    return peak_len;
}

char* processStr(char* s)
{
    assert(s != NULL);
    const isize peak_res_len = peak_result_len(s);
    char* res = malloc((size_t)(peak_res_len + 1) * sizeof(*res));
    assert(res != NULL);
    isize res_idx = 0;

    for (isize i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == '#') {
            for (isize j = 0; j < res_idx; j += 1) {
                res[res_idx + j] = res[j];
            }
            res_idx *= 2;
        } else if (s[i] >= 'a' && s[i]  <= 'z') {
            res[res_idx] = s[i];
            res_idx += 1;
        } else if (s[i] == '*') {
            res_idx = max_isize(0, res_idx - 1);
        } else if (s[i] == '%') {
            reverse(res, 0, res_idx);
        } else {
            fprintf(stderr, "invalid input");
            abort();
        }
    }

    res[res_idx] = '\0';
    return res;
}
