int longestCommonSubsequence(char* text1, char* text2)
{
    char* t1 = text1;
    char* t2 = text2;
    size_t t1_len = strlen(t1);
    size_t t2_len = strlen(t2);

    if (t1_len < t2_len) {
        char* temp_ch = t1;
        t1 = t2;
        t2 = temp_ch;

        size_t temp_len = t1_len;
        t1_len = t2_len;
        t2_len = temp_len;
    }

    const size_t dp_cols = t2_len + 1;
    int* dp = (int*) calloc(2 * dp_cols, sizeof(*dp));
    int* curr = dp;
    int* prev = dp + dp_cols;

    for (ptrdiff_t i = (ptrdiff_t) t1_len - 1; i >= 0; i -= 1) {
        for (ptrdiff_t j = (ptrdiff_t) t2_len - 1; j >= 0; j -= 1) {
            if (t1[i] == t2[j]) {
                curr[j] = 1 + prev[j + 1];
            } else {
                const int right = curr[j + 1];
                const int down = prev[j];
                curr[j] = right > down ? right : down;
            }
        }

       int* temp = prev;
       prev = curr;
       curr = temp;
    }

    const int res = prev[0];

cleanup:
    free(dp);
    return res;
}
