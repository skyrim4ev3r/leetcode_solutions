#define EXACT_ALLOWED_WEIGHTS_LEN 26

char* mapWordWeights(char** words, int words_len_i32, int* weights, int weights_len_i32)
{
    assert(words != NULL && words_len_i32 >= 1 && weights != NULL && weights_len_i32 == EXACT_ALLOWED_WEIGHTS_LEN);

    ptrdiff_t words_len = words_len_i32;
    char* res = malloc((size_t)(words_len + 1) * sizeof(*res));
    ptrdiff_t res_idx = 0;
    assert(res != NULL);

    for (ptrdiff_t i = 0; i < words_len; i += 1) {
        char* curr_word = words[i];
        assert(curr_word != NULL);
        int curr_sum = 0;

        for (ptrdiff_t j = 0; curr_word[j] != '\0'; j += 1) {
            const char ch = curr_word[j];
            assert(ch >= 'a' && ch <= 'z');
            curr_sum += weights[ch - 'a'];
        }

        const int reversed_offset = 25 - (curr_sum % 26);
        res[res_idx] = (char)(reversed_offset + 'a');
        res_idx += 1;
    }
    res[res_idx] = '\0';
    return res;
}
