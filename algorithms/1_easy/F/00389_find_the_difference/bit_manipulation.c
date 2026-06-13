char findTheDifference(char* s, char* t)
{
    assert(s != NULL && t != NULL);
    char added_char = 0;

    for (ptrdiff_t i = 0; s[i] != '\0'; i += 1) {
        added_char ^= s[i];
    }

    for (ptrdiff_t i = 0; t[i] != '\0'; i += 1) {
        added_char ^= t[i];
    }

    return added_char;
}
