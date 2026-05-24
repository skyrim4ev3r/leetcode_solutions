char* countAndSay(int n) {
    size_t len = 1;
    char* res = (char*) malloc((len + 1) * sizeof(char));
    res[0] = '1';
    res[1] = '\0';

    for(int i = 1; i < n; i += 1) {
        const size_t new_len = 1 + len * 2;
        char* new_res = (char*) malloc(new_len * sizeof(char));
        size_t left = 0;
        size_t right = 0;
        size_t curr_pos = 0;

        while (res[right] != '\0') {
            while (res[right] != '\0' && res[right] == res[left]) {
                right += 1;
            }

            size_t temp = right - left;
            size_t p = 1;
            while (temp >= p) {
                p *= 10;
            }
            p /= 10;

            while (p > 0) {
                new_res[curr_pos] = (temp / p) + '0';
                curr_pos += 1;
                temp %= p;
                p /= 10;
            }

            new_res[curr_pos] = res[left];
            curr_pos += 1;
            left = right;
        }

        new_res[curr_pos] = '\0';
        curr_pos += 1;
        free(res);
        res = new_res;
        len = curr_pos;
    }

    return res;
}
