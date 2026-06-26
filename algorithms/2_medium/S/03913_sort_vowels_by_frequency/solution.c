#define VOWELS_LEN 5

typedef ptrdiff_t isize;

struct entity {
    int freq;
    char ch;
};

static void sort_table(struct entity* table, isize len) {
    for (isize i = 1; i < len; i++) {
        struct entity key = table[i];
        isize j = i - 1;
        while (j >= 0 && table[j].freq < key.freq) {
            table[j + 1] = table[j];
            j -= 1;
        }
        table[j + 1] = key;
    }
}

static inline bool is_vowel(const char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

static inline bool inc_freq(struct entity* table, const isize len, const char ch)
{
    for (isize i = 0; i < len; i += 1) {
        if (table[i].ch == ch) {
            table[i].freq += 1;
            return true;
        }
    }

    return false;
}

char* sortVowels(char* s)
{
    assert(s != NULL);
    struct entity table[VOWELS_LEN];
    isize table_len = 0;

    for (isize i = 0; s[i] != '\0'; i += 1) {
        const char ch = s[i];
        if (is_vowel(ch)) {
            if (!inc_freq(table, table_len, ch)) {
                assert(table_len < VOWELS_LEN);
                table[table_len] = (struct entity) { freq: 1, ch: ch};
                table_len += 1;
            }
        }
    }

    sort_table(table, table_len);
    isize table_idx = 0;
    for (isize i = 0; s[i] != '\0'; i += 1) {
        if (is_vowel(s[i])) {
            s[i] = table[table_idx].ch;
            table[table_idx].freq -= 1;
            if (table[table_idx].freq == 0) {
                table_idx += 1;
            }
        }
    }

    return s;
}
