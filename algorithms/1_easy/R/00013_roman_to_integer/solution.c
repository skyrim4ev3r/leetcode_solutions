static inline int get_val(const char key) {
    switch (key) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    };
}

int romanToInt(const char* s) {
    const size_t len = strlen(s);
    int sum = 0;
    int curr_max = 0;

    for (size_t i = len - 1; i < len; --i) {
        const int val = get_val(s[i]);

        if (val >= curr_max) {
            sum += val;
            curr_max = val;
        } else {
            sum -= val;
        }
    }

    return sum;
}
