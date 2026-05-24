static inline size_t calc_pos(char** strs, size_t input_len)
{
    size_t pos = 0;
    while (strs[0][pos] != '\0') {
        for (size_t i = 1; i < input_len; ++i) {
            if (strs[i][pos] != strs[i - 1][pos]) {
                return pos;
            }
        }

        pos += 1;
    }
    return pos;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
    size_t pos = calc_pos(strs, strsSize);
    char* res = (char*) malloc((pos + 1) * sizeof(char));
    memcpy(res, strs[0], pos);
    res[pos] = '\0';
    return res;
}
