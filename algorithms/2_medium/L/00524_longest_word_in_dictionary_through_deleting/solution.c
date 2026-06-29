typedef ptrdiff_t isize;

static bool is_sub(const char* s, const isize s_len, const char* t, const isize t_len)
{
    assert(s != NULL && t != NULL);

    if (s_len < t_len) { return false; }

    if (t_len == 0) { return true; }

    isize t_idx = 0;

    for (isize s_idx = 0; s[s_idx] != '\0'; s_idx += 1) {
        if (s[s_idx] == t[t_idx]) {
            t_idx += 1;

            if (t[t_idx] == '\0') {
                return true;
            }
        }

        if (s_len - s_idx < t_len - t_idx) {
            return false;
        }
    }

    return false;
}

char* findLongestWord(char* s, char** dictionary, int dictionary_len_int)
{
    assert(s != NULL && dictionary != NULL && dictionary_len_int > 0);
    const isize dictionary_len = dictionary_len_int;
    const isize s_len = (isize)strlen(s);
    isize selected_idx = -1;
    isize selected_len = -1;

    for (isize i = 0; i < dictionary_len; i += 1) {
        const isize curr_len = (isize)strlen(dictionary[i]);
        if (is_sub(s, s_len, dictionary[i], curr_len)) {
            if (selected_len < curr_len) {
                selected_idx = i;
                selected_len = curr_len;
            } else if (selected_len == curr_len && strcmp(dictionary[selected_idx], dictionary[i]) > 0) {
                selected_idx = i;
            }
        }
    }

    if (selected_idx == -1) {
        char* res = "";
        return res;
    }

    return dictionary[selected_idx];
}

