bool isSubsequence(char* s, char* t)
{
    assert(s != NULL && t != NULL);
    ptrdiff_t s_idx = 0;
    ptrdiff_t t_idx = 0;

    while (s[s_idx] != '\0' && t[t_idx] != '\0') {
        if (s[s_idx] == t[t_idx]) {
            s_idx += 1;
        }

        t_idx += 1;
    }

    return s[s_idx] == '\0';
}
