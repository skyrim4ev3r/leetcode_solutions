struct vec_int {
    int* ptr;
    size_t len;
};

static inline struct vec_int vec_int_with_capacity(size_t cap)
{
    struct vec_int init_vec = {
        ptr: (int*) malloc(cap * sizeof(*init_vec.ptr)),
        len: 0,
    };

    return init_vec;
}

static void vec_int_push(struct vec_int* vec, int val)
{
    vec->ptr[vec->len] = val;
    vec->len += 1;
}

static void vec_int_clear(struct vec_int* vec)
{
    vec->len = 0;
}

static void vec_int_swap(struct vec_int* vec1, struct vec_int* vec2)
{
    // struct vec_int vec_temp = *vec1;
    // *vec1 =*vec2;
    // *vec2 = vec_temp;

    int* ptr1 = vec1->ptr;
    vec1->ptr = vec2->ptr;
    vec2->ptr = ptr1;

    int len1 = vec1->len;
    vec1->len = vec2->len;
    vec2->len = len1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    const size_t final_len = 1 + (size_t) rowIndex;
    *returnSize = (int) final_len;
    struct vec_int curr = vec_int_with_capacity(final_len);
    vec_int_push(&curr, 1);
    struct vec_int next = vec_int_with_capacity(final_len);

    while (curr.len != final_len) {
        const size_t curr_len = curr.len;

        vec_int_clear(&next);
        vec_int_push(&next, 1); // First element always 1
        for (size_t i = 1; i < curr_len; ++i) {
            vec_int_push(&next, curr.ptr[i] + curr.ptr[i - 1]);
        }
        vec_int_push(&next, 1); // Last element always 1

        vec_int_swap(&curr, &next);
    }

cleanup:
    free(next.ptr);
    return curr.ptr;
}
