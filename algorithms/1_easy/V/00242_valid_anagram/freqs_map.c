#define FREQS_LEN 26

bool isAnagram(char* s, char* t)
{
    assert(s != NULL && t != NULL);
    int freqs[FREQS_LEN] = { 0 };
    ptrdiff_t i = 0;

    while (s[i] != '\0' && t[i] != '\0') {
        assert(s[i] >= 'a' && s[i] <= 'z' && t[i] >= 'a' && t[i] <= 'z');
        freqs[s[i] - 'a'] += 1;
        freqs[t[i] - 'a'] -= 1;
        i += 1;
    }

    if (s[i] != '\0' || t[i] != '\0') {
        return false;
    }

    for (ptrdiff_t i = 0; i < FREQS_LEN; i += 1) {
        if (freqs[i] != 0) {
            return false;
        }
    }

    return true;
}
