bool canConstruct(char* ransom_note, char* magazine)
{
    assert(ransom_note != NULL && magazine != NULL);
    ptrdiff_t freqs[26] = { 0 };

    for (ptrdiff_t i = 0; magazine[i] != '\0'; i += 1) {
        const char ch = magazine[i];
        assert(ch >= 'a' && ch <= 'z');
        freqs[ch -'a'] += 1;
    }

    for (ptrdiff_t i = 0; ransom_note[i] != '\0'; i += 1) {
        const char ch = ransom_note[i];
        assert(ch >= 'a' && ch <= 'z');
        ptrdiff_t* freq = &freqs[ch -'a'];

        if (*freq == 0) {
            return false;
        }

        *freq -= 1;
    }

    return true;
}
