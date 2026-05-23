static void check_palindrom(const char* s, size_t left, size_t right,
                            size_t* max_width, size_t* max_width_start_idx)
{
    while (left > 0 && s[right + 1] != '\0' && s[left - 1] == s[right + 1]) {
        left -= 1;
        right += 1;
    }

    const size_t curr_width = right - left + 1;

    if (curr_width > *max_width) {
        *max_width = curr_width;
        *max_width_start_idx = left;
    }
}

char* longestPalindrome(char* s) {
    size_t max_width = 0;
    size_t max_width_start_idx = 0;

    for (size_t i = 0; s[i] != '\0'; ++i) {
        if (i > 0 && s[i - 1] == s[i]) {
            check_palindrom(s, i - 1, i, &max_width, &max_width_start_idx);
        }
        check_palindrom(s, i, i, &max_width, &max_width_start_idx);
    }

    char* res = (char*) malloc(max_width * sizeof(char) + 1);
    res[max_width] = '\0';
    strncpy(res, s + max_width_start_idx, max_width);
    free(s);
    return res;
}
