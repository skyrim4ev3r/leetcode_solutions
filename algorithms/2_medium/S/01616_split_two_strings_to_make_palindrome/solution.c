typedef ptrdiff_t isize;

struct slice_char {
    char* ptr;
    isize len;
};

static inline bool is_palindrome(struct slice_char b)
{
    const isize len = b.len;
    const char* ptr = b.ptr;
    if (len <= 1) { return true; }
    isize lo = 0;
    isize hi = len - 1;

    while (lo < hi) {
        if (ptr[lo] != ptr[hi]) {
            return false;
        }

        lo += 1;
        hi -= 1;
    }

    return true;
}

static inline bool is_palindrome_by_split(const char* b1, const char* b2, const isize len)
{
    if (len <= 1) { return true; }

    isize lo = 0;
    isize hi = len - 1;

    while (lo < hi && b1[lo] == b2[hi]) {
        lo += 1;
        hi -= 1;
    }

    struct slice_char use_b1 = { ptr: &b1[lo], len: hi - lo + 1};
    struct slice_char use_b2 = { ptr: &b2[lo], len: hi - lo + 1};

    return is_palindrome(use_b1) || is_palindrome(use_b2);
}

bool checkPalindromeFormation(char* b1, char* b2)
{
    assert(b1 != NULL && b2 != NULL);
    const isize len = (isize)strlen(b1);
    assert(b2[len] == '\0');

    return is_palindrome_by_split(b1, b2, len) || is_palindrome_by_split(b2, b1, len);
}
