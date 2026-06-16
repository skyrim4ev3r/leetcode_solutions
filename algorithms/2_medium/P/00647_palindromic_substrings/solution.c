typedef ptrdiff_t isize;

static int calc_len_palindrome(const char* s, isize lo, isize hi)
{
    if (lo < 0 || s[hi] == '\0' || s[lo] != s[hi]) {
        return 0;
    }

    while (lo >= 0 && s[hi] != '\0' && s[lo] == s[hi]) {
        lo -= 1;
        hi += 1;
    }

    return (int)(hi - lo - 1);
}

int countSubstrings(char* s)
{
    assert(s != NULL);
    int cnt = 0;

    for (isize i = 0; s[i] != '\0'; i += 1) {
        const int len_odd = calc_len_palindrome(s, i, i);
        const int len_even = calc_len_palindrome(s, i - 1, i);

        cnt += ((len_odd + 1) / 2) + (len_even / 2);
    }

    return cnt;
}
