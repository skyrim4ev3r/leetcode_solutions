int myAtoi(const char* s) {
    bool is_negative = false;
    size_t index = 0;

    while (s[index] != '\0' &&  s[index] == ' ') {
        index += 1;
    }

    if (s[index] == '\0') {
        return 0;
    }

    if (s[index] == '-') {
        is_negative = true;
    }

    if (s[index] == '-' || s[index] == '+') {
        index += 1;
    }

    int64_t res = 0;

    while (s[index] >= '0' && s[index] <= '9') {
        res *= 10;
        res += s[index] - '0';
        index += 1;

        if (is_negative && (res * -1 < INT32_MIN)) {
            return INT32_MIN;
        } 

        if (!is_negative && res > INT32_MAX) {
            return INT32_MAX;
        }
    }

    if (is_negative) {
        res *= -1;
    }

    return (int) res;
}
