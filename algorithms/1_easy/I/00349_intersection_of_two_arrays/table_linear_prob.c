struct entity {
    int val;
    bool is_fill;
    bool in_nums1;
    bool in_nums2;
};

struct table {
    struct entity* arr;
    size_t len;
};

static inline struct table new_table(const ptrdiff_t len)
{
    struct entity* arr = malloc((size_t)len * sizeof(*arr));
    assert(arr != NULL);

    for (ptrdiff_t i = 0; i < len; i += 1) {
        arr[i].val = -1;
        arr[i].is_fill = false;
        arr[i].in_nums1 = false;
        arr[i].in_nums2 = false;
    }

    struct table res = { 
        arr: arr,
        len: (size_t)len,
    };

    return res;
}

static inline void free_data_table(struct table* set)
{
    if (set == NULL) { return; }
    free(set->arr);
    set->arr = NULL;
    set->len = 0;
}

static inline ptrdiff_t calc_idx_table(struct table* set, const int a)
{
    const ptrdiff_t len = (ptrdiff_t)set->len;
    return ((a % len) + len) % len;
}

static inline ptrdiff_t next_idx_table(struct table* set, const ptrdiff_t idx)
{
    const ptrdiff_t len = (ptrdiff_t)set->len;
    return idx + 1 == len ? 0 : idx + 1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1_size, int* nums2, int nums2_size, int* return_size)
{
    assert(nums1_size >= 0 && nums2_size >= 0 && nums1 != NULL && nums2 != NULL && return_size != NULL);
    if (nums1_size > nums2_size) {
        const int temp_size = nums1_size;
        nums1_size = nums2_size;
        nums2_size = temp_size;

        int* temp_ptr = nums1;
        nums1 = nums2;
        nums2 = temp_ptr;
    }

    const ptrdiff_t len1 = nums1_size;
    const ptrdiff_t len2 = nums2_size;
    const ptrdiff_t len_table = 2 * (ptrdiff_t)nums1_size;
    struct table set = new_table(len_table);

    for (ptrdiff_t i = 0; i < len1; i += 1) {
        const int num = nums1[i];
        ptrdiff_t idx_num = calc_idx_table(&set, num);
        while (set.arr[idx_num].is_fill) {
            if (set.arr[idx_num].val == num) {
                break;
            }
            idx_num = next_idx_table(&set, idx_num);
        }
        set.arr[idx_num].is_fill = true;
        set.arr[idx_num].in_nums1 = true;
        set.arr[idx_num].val = num;
    }

    for (ptrdiff_t i = 0; i < len2; i += 1) {
        const int num = nums2[i];
        ptrdiff_t idx_num = calc_idx_table(&set, num);
        while (set.arr[idx_num].is_fill) {
            if (set.arr[idx_num].val == num) {
                set.arr[idx_num].in_nums2 = true;
                break;
            }
            idx_num = next_idx_table(&set, idx_num);
        }
    }

    ptrdiff_t count = 0;
    for (ptrdiff_t i = 0; i < len_table; i += 1) {
        if (set.arr[i].in_nums2) {
            count += 1;
        }
    }

    *return_size = (int)count;

    int* res = malloc((size_t)count * sizeof(*res));
    assert(res != NULL);
    ptrdiff_t res_idx = 0;

    for (ptrdiff_t i = 0; i < len_table; i += 1) {
        if (set.arr[i].in_nums2) {
            res[res_idx] = set.arr[i].val;
            res_idx += 1;
        }
    }

/* cleanup: */
    free_data_table(&set);
    return res;
}
