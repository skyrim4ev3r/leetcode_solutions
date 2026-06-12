struct data {
    uint32_t mask;
    int word_len;
};

int maxProduct(char** words, int words_size)
{
    assert(words != NULL && words_size >= 2);
    ptrdiff_t len = words_size;
    struct data* datas = malloc((size_t)len * sizeof(*datas));

    for (ptrdiff_t i = 0; i < len; i += 1) {
        char* word = words[i];
        uint32_t mask = 0;
        ptrdiff_t j = 0;

        for (j = 0; word[j] != '\0'; j += 1) {
            assert(word[j] >= 'a' && word[j] <= 'z');
            mask |= (1 << (word[j] - 'a'));
        }

        datas[i].mask = mask;
        assert(j <= INT_MAX);
        datas[i].word_len = (int)j;
    }

    int max_product_len = 0;

    for (ptrdiff_t i = 0; i < len; i += 1) {
        for (ptrdiff_t j = i + 1; j < len; j += 1) {
            if ((datas[i].mask & datas[j].mask) == 0) {
                assert(datas[i].word_len <= INT_MAX / datas[j].word_len);
                const int curr_prod = datas[i].word_len * datas[j].word_len;
                if (curr_prod > max_product_len) {
                    max_product_len = curr_prod;
                }
            }
        }
    }

cleanup:
    free(datas);
    return max_product_len;
}
