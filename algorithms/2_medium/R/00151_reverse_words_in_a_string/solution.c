static inline void rev(char* s, size_t left, const size_t right_exclusive)
{
    if (right_exclusive <= left) {
        return;
    }

    size_t right = right_exclusive - 1;

    while (left < right) {
        const char temp = s[right];
        s[right] = s[left];
        s[left] = temp;

        left += 1;
        right -= 1;
    }
}

char* reverseWords(char* s)
{
    size_t left = 0;
    size_t write_idx = 0;

    while (true) {
        while (s[left] == ' ') {
            left += 1;
        }

        if (s[left] == '\0') {
            break;
        }

        size_t right = left;
        while (s[right] != '\0' && s[right] != ' ') {
            right += 1;
        }

        rev(s, left, right);

        if (write_idx > 0) {
            s[write_idx] = ' ';
            write_idx += 1;
        }

        while (left != right) {
            s[write_idx] = s[left];
            left += 1;
            write_idx += 1;
        }
    }

    s[write_idx] = '\0';
    rev(s, 0, write_idx);

    return s;
}
