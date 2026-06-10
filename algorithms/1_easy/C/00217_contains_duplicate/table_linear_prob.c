struct entry {
    int val;
    bool is_fill;
};

bool containsDuplicate(int* nums, int nums_len_i32) {
    const ptrdiff_t nums_len = nums_len_i32;
    assert(nums != NULL && nums_len > 0);
    const ptrdiff_t table_len = 2 * nums_len;
    struct entry* table = calloc((size_t) table_len, sizeof(*table));
    assert(table != NULL);

    for (ptrdiff_t i = 0; i < nums_len; i += 1){
        const int val = nums[i];
        ptrdiff_t idx = (((ptrdiff_t) val % table_len) + table_len) % table_len;

        while (table[idx].is_fill == true) {
            if (table[idx].val == val) {
                return true;
            }
            idx = (idx + 1 == table_len) ? 0 : idx + 1;
        }

        table[idx].is_fill = true;
        table[idx].val = val;
    }

cleanup:
    free(table);
    return false;
}
