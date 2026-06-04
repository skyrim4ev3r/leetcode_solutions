static inline size_t max_usize(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

struct vec_char {
    char* ptr;
    size_t len;
    size_t cap;
};

static inline struct vec_char vec_char_new()
{
    struct vec_char init_res = { ptr:NULL, len: 0, cap: 0 };
    return init_res;
}

static inline void vec_char_push(struct vec_char* vec, const char ch)
{
    if (vec->cap == vec->len) {
        const size_t new_cap = max_usize(2 * vec->cap, 4);
        vec->ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        vec->cap = new_cap;
    }
    vec->ptr[vec->len] = ch;
    vec->len += 1;
}

static inline void vec_char_rev(struct vec_char* vec)
{
    const size_t len = vec->len;
    if (len <= 1) {
        return;
    }

    char* ptr = vec->ptr;
    size_t left = 0;
    size_t right = len - 1;

    while (left < right) {
        const char temp = ptr[left];
        ptr[left] = ptr[right];
        ptr[right] = temp;
        left += 1;
        right -= 1;
    }
}

static inline char* vec_char_into_owned(struct vec_char* vec)
{
    char* res = vec->ptr;
    const size_t len = vec->len;
    const size_t cap = vec->cap;

    vec->ptr = NULL;
    vec->len = 0;
    vec->cap = 0;

    if (cap == len) {
        res = realloc(res , (cap + 1) * sizeof(*res));
    }

    res[len] = '\0';

    return res;
}

char* convertToTitle(int col_number)
{
    struct vec_char res = vec_char_new();

    while (col_number >= 1) {
        const int rem = (col_number - 1) % 26;
        vec_char_push(&res, (char) (rem + 'A'));
        col_number = (col_number - 1) / 26;
    }

    vec_char_rev(&res);

    return vec_char_into_owned(&res);
}
