static void backtrack(char* res, const char* pattern, const int target_len, const int curr_idx, 
                      uint32_t seen, bool* res_ready)
{
    if (curr_idx == target_len) {
        *res_ready = true;
        return;
    }

    for (uint32_t i = 1; i <= 9; i += 1) {
        const uint32_t mask = 1 << i;
        if ((seen & mask) == 0) {
            if (curr_idx > 0 && pattern[curr_idx - 1] == 'I' && (res[curr_idx - 1] - '0') > i) {
                continue;
            }

            if (curr_idx > 0 && pattern[curr_idx - 1] == 'D' && (res[curr_idx - 1] - '0') < i) {
                break;
            }
            res[curr_idx] = i + '0';
            backtrack(res, pattern, target_len, curr_idx + 1, seen | mask, res_ready);
        }

        if (*res_ready) {
            return;
        }
    }
}

char* smallestNumber(char* pattern)
{
    assert(pattern != NULL);
    const size_t pattern_len = strlen(pattern);
    assert(pattern_len <= 8);
    char* res = malloc((pattern_len + 2) * sizeof(*res));
    assert(res != NULL);
    res[pattern_len + 1] = '\0';
    bool res_ready = false;
    uint32_t seen = 0;
    const int target_len = (int)pattern_len + 1;

    backtrack(res, pattern, target_len, 0, seen, &res_ready);

    return res;
}
