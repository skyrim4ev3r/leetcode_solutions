int numOfStrings(char** patterns, int patterns_len, char* word) {
    assert(patterns != NULL && patterns_len > 0 && word != NULL);
    int count = 0;

    for (int i = 0; i < patterns_len; i += 1) {
        if (strstr(word, patterns[i]) != NULL) {
            count += 1;
        }
    }

    return count;
}
