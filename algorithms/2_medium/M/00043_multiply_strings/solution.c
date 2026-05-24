char* multiply(char* num1, char* num2)
{
    if (num1[0] == '0' || num2[0] == '0') {
        return "0";
    }

    const size_t len1 = strlen(num1);
    const size_t len2 = strlen(num2);
    const size_t max_len = len1 > len2 ? len1 : len2;
    char* res = (char*) malloc((max_len + 1) * 2 * sizeof(char));
    size_t res_len = 0;

    for (size_t i = 0; i < len1; i += 1) {
        char carry = 0;

        for(size_t j = 0; j < len2; j += 1) {
            const size_t pos = i + j;

            if (pos >= res_len) {
                res[res_len] = 0;
                res_len += 1;
            }

            const char curr_val = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0') + carry + res[pos];
            res[pos] =  curr_val % 10;
            carry = curr_val / 10;
        }

        if (carry > 0) {
            res[res_len] = carry;
            res_len += 1;
        }
    }

    for (size_t i = 0; i < res_len; i += 1) {
        res[i] += '0';
    }
    res[res_len] = '\0';

    size_t left = 0;
    size_t right = res_len - 1;

    while (left < right) {
        const char temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left += 1;
        right -= 1;
    }

    return res;
}
