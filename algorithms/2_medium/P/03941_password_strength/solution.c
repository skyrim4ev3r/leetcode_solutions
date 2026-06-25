#define TABLE_SIZE 256

typedef ptrdiff_t isize;

int passwordStrength(char* password)
{
    assert(password != NULL);
    bool seen[TABLE_SIZE] = { false };

    for (isize i = 0; password[i] != '\0'; i += 1) {
        seen[(unsigned char)password[i]] = true;
    }

    int score = 0;

    for (int byte = 0; byte < TABLE_SIZE; byte += 1) {
        if (seen[byte]) {
            if ('a' <= byte && byte <= 'z') {
                score += 1;
            } else if ('A' <= byte && byte <= 'Z') {
                score += 2;
            } else if ('0' <= byte && byte <= '9') {
                score += 3;
            } else if (byte == '!' || byte == '@' || byte == '#' || byte == '$') {
                score += 5;
            }
        }
    }

    return score;
}
