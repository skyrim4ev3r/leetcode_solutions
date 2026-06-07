#define TABLE_SIZE 256
#define UNSEEN -1

bool isIsomorphic(char* s, char* t)
{
    ptrdiff_t s_first_seen[TABLE_SIZE];
    ptrdiff_t t_first_seen[TABLE_SIZE];

    for (ptrdiff_t i = 0; i < TABLE_SIZE; i++) {
        s_first_seen[i] = UNSEEN;
        t_first_seen[i] = UNSEEN;
    }

    ptrdiff_t i = 0;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i += 1) {
        const ptrdiff_t ch_s_idx = (ptrdiff_t) (unsigned char) s[i];
        const ptrdiff_t ch_t_idx = (ptrdiff_t) (unsigned char) t[i];

        if (s_first_seen[ch_s_idx] == UNSEEN) {
            s_first_seen[ch_s_idx] = i;
        }

        if (t_first_seen[ch_t_idx] == UNSEEN) {
            t_first_seen[ch_t_idx] = i;
        }

        if (s_first_seen[ch_s_idx] != t_first_seen[ch_t_idx]) {
            return false;
        }
    }

    return s[i] == '\0' && t[i] == '\0';
}
