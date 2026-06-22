#define ISIZE_MAX PTRDIFF_MAX
#define TABLE_SIZE 256

typedef ptrdiff_t isize;

static inline isize min_isize(const isize a, const isize b)
{
    return a < b ? a : b;
}

static int max_formations_of(const char* source, const char* target)
{
    if (source == NULL || target == NULL || target[0] == '\0') { return 0; }
    isize freqs_source[TABLE_SIZE] = { 0 };
    isize freqs_target[TABLE_SIZE] = { 0 };

    for (isize i = 0; source[i] != '\0'; i += 1) { freqs_source[(unsigned char)source[i]]  += 1; }
    for (isize i = 0; target[i] != '\0'; i += 1) { freqs_target[(unsigned char)target[i]]  += 1; }

    isize res = ISIZE_MAX;

    for (isize i = 0; i < TABLE_SIZE; i += 1) {
        if (freqs_target[i] > 0) {
            res = min_isize(res, freqs_source[i] / freqs_target[i]);
        }
    }

    assert(res <= (isize)INT_MAX);
    return (int)res;
}

int maxNumberOfBalloons(char* text)
{
    return max_formations_of(text, "balloon");
}
