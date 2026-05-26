int numberOfSpecialChars(char* word)
{
    uint8_t flags[26] = { 0 };

    for (size_t i = 0; word[i] != '\0'; i += 1) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            flags[(size_t) (word[i] - 'a')] |= 1;
        } else {
            flags[(size_t) (word[i] - 'A')] |= 2;
        }
    }

    int count = 0;

    for (size_t i = 0; i < 26; i += 1) {
        if (flags[i] == 3) {
            count += 1;
        }
    }

    return count;
}
