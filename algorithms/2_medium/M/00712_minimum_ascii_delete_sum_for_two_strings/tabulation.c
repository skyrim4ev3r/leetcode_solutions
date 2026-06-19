typedef ptrdiff_t isize;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

int minimumDeleteSum(char* s1, char* s2)
{
    assert(s1 != NULL && s2 != NULL);
    isize len1 = strlen(s1);
    isize len2 = strlen(s2);
    if (len1 < len2) { 
        isize temp_len = len1;
        len1 = len2;
        len2 = temp_len;

        char* temp_s = s1;
        s1 = s2;
        s2 = temp_s;
    }

    int* dp = malloc(2 * (len2 + 1) * sizeof(*dp));
    assert(dp != NULL);
    int* curr = &dp[0];
    int* next = &dp[len2 + 1];
    next[len2] = 0;
    for (isize j = len2 - 1; j >= 0; j -= 1) {
        next[j] = next[j + 1] + s2[j];
    }

    for (isize idx1 = len1 - 1; idx1 >= 0; idx1 -= 1) {
        curr[len2] = next[len2] + s1[idx1];

        for (isize idx2 = len2 - 1; idx2 >= 0; idx2 -= 1) {
            if (s1[idx1] == s2[idx2]) {
                curr[idx2] = next[idx2 + 1];
            } else {
                curr[idx2] = min_int(curr[idx2 + 1] + s2[idx2], next[idx2] + s1[idx1]);
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
