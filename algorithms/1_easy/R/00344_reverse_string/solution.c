void reverseString(char* s, int s_size)
{
    assert(s != NULL && s_size >= 0);
    ptrdiff_t lo = 0;
    ptrdiff_t hi = s_size - 1;

    while (lo < hi) {
        const char temp = s[lo];
        s[lo] = s[hi];
        s[hi] = temp;

        lo += 1;
        hi -= 1;
    }
}
