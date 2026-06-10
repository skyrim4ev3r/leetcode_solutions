struct hash_set {
    int key;
    UT_hash_handle hh;
};

static inline void free_hash_set(struct hash_set* set)
{
    struct hash_set *current;
    struct hash_set *tmp;
    HASH_ITER(hh, set, current, tmp) {
        HASH_DEL(set, current);
        free(current);
    }
}

bool containsDuplicate(int* nums, int nums_size)
{
    const ptrdiff_t len = nums_size;
    assert(nums != NULL && len > 0);

    struct hash_set *set = NULL;
    struct hash_set *entry = NULL;

    for (ptrdiff_t i = 0; i < len; i++) {
        HASH_FIND_INT(set, &nums[i], entry);

        if (!entry) {
            entry = malloc(sizeof(struct hash_set));
            assert(entry != NULL);
            entry->key = nums[i];
            HASH_ADD_INT(set, key, entry);
        } else {    
            free_hash_set(set);
            return true;
        }
    }

    free_hash_set(set);
    return false;
}
