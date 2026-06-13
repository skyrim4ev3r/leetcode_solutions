#define FREQS_LEN 26

char findTheDifference(char* s, char* t)
{
    assert(s != NULL && t != NULL);
    int freqs[FREQS_LEN] = { 0 };

    for (ptrdiff_t i = 0; s[i] != '\0'; i += 1) {
        const char ch = s[i];
        assert(ch >= 'a' && ch <= 'z');
        freqs[ch - 'a'] += 1;
    }

    for (ptrdiff_t i = 0; t[i] != '\0'; i += 1) {
        const char ch = t[i];
        assert(ch >= 'a' && ch <= 'z');
        freqs[ch - 'a'] -= 1;
    }

    for (ptrdiff_t i = 0; i < FREQS_LEN; ++i) {
        if (freqs[i] != 0) {
            return (char)(i + 'a');
        }
    }

    printf("invalid input");
    abort();
}
