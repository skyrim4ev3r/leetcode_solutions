struct string {
    char* val;
    size_t len;
    size_t capacity;
};

static inline struct string str_with_capacity(size_t capacity)
{
    struct string res = {
        val: (char*) malloc(capacity * sizeof(char)),
        len: 0,
        capacity: capacity,
    };

    return res;
}

static inline void str_add_auto_capacity(struct string* str)
{
    size_t capacity = str->capacity;
    capacity *= 2;
    if (capacity == 0) {
        capacity = 1;
    }
    str->val = (char*) realloc(str->val, capacity * sizeof(char));
    str->capacity = capacity;
}

static void str_push(struct string* str, char ch)
{
    if (str->len == str->capacity) {
        str_add_auto_capacity(str);
    }

    str->val[str->len] = ch;
    str->len += 1;
}

static void str_reverse(struct string* str)
{
    if (str->len <= 1) {
        return;
    }

    size_t right = (str->len) - 1;
    size_t left = 0;
    char* val = str->val;

    while (left < right) {
        char temp = val[left];
        val[left] = val[right];
        val[right] = temp;
        left += 1;
        right -= 1;
    }
}

static inline char* str_into_owned(struct string* str) {
    char* val = str->val;
    str->val = NULL;
    const size_t len = str->len;
    str->len = 0;
    const size_t capacity = str->capacity;
    str->capacity = 0;

    if (len == capacity) {
        val = (char*) realloc(val, (len + 1) * sizeof(char));
    }

    val[len] = '\0';
    return val;
}

char* intToRoman(int num)
{
    size_t steps = 0;
    struct string res = str_with_capacity(20);

    static const char map_steps[4][3] = {
        {'I','V','X'},
        {'X','L','C'},
        {'C','D','M'},
        {'M','M','M'}
    };

    while (num > 0) {
        const int rem = num % 10;
        num /= 10;

        switch (rem) {
            case 1:
                str_push(&res, map_steps[steps][0]);
                break;
            case 2:
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                break;
            case 3:
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                break;
            case 4:
                str_push(&res, map_steps[steps][1]);
                str_push(&res, map_steps[steps][0]);
                break;
            case 5:
                str_push(&res, map_steps[steps][1]);
                break;
            case 6:
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][1]);
                break;
            case 7:
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][1]);
                break;
            case 8:
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][0]);
                str_push(&res, map_steps[steps][1]);
                break;
            case 9:
                str_push(&res, map_steps[steps][2]);
                str_push(&res, map_steps[steps][0]);
                break;
            default:
                break;
        };

        steps += 1;
    }

    str_reverse(&res);

    return str_into_owned(&res);
}
