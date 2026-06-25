static void backtrack(const int curr_len, const int target_len,
                      const int curr_cost, const int target_max_cost, const bool prev_is_one,
                      char*** res, int* res_len, int* res_cap,
                      char* temp)
{
    if (curr_cost > target_max_cost) { return; }

    if (curr_len == target_len) {
        char* v = malloc((size_t)(curr_len + 1) * sizeof(*v));
        assert(v != NULL);
        v[curr_len] = '\0';
        for (int i = 0; i < curr_len; i+= 1) { v[i] = temp[i]; }

        if (*res_len == *res_cap) {
            const int new_cap = *res_cap == 0 ? 4 : (*res_cap * 2);
            *res = realloc(*res, (size_t)new_cap * sizeof(**res));
            assert(*res != NULL);
            *res_cap = new_cap;
        }

        (*res)[*res_len] = v;
        *res_len += 1;
        return;
    }

    temp[curr_len] = ('0');
    backtrack(curr_len + 1, target_len, curr_cost, target_max_cost, false, res, res_len, res_cap, temp);

    if (!prev_is_one) {
        temp[curr_len] = ('1');
        backtrack(curr_len + 1, target_len, curr_cost + curr_len, target_max_cost, true, res, res_len, res_cap, temp);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateValidStrings(int target_len, int target_max_cost, int* return_size)
{
    assert(target_len >= 1 && target_len <= 12 && target_max_cost >= 0 && return_size != NULL);
    int res_len = 0;
    int res_cap = 0;
    char** res = NULL;
    char* temp = malloc((size_t)(target_len + 1) * sizeof(*temp));
    assert(temp != NULL);
    temp[target_len] = '\0';

    backtrack(0, target_len, 0, target_max_cost, false, &res, &res_len, &res_cap, temp);
    *return_size = res_len;

/* cleanup: */
    free(temp);
    return res;
}
