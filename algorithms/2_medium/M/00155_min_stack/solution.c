static inline size_t max_usize(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

struct vec_int {
    int* ptr;
    size_t len;
    size_t cap;
};

static inline struct vec_int vec_int_new()
{
    struct vec_int res = {
        ptr: NULL,
        len: 0,
        cap: 0,
    };
    return res;
}

static inline void vec_int_free(struct vec_int* vec)
{
    free(vec->ptr);
    vec->len = 0;
    vec->cap = 0;
}

static inline bool vec_int_is_empty(struct vec_int* vec)
{
    return vec->len == 0;
}

static inline int vec_int_top(struct vec_int* vec)
{
    return vec->ptr[vec->len - 1];
}

static inline void vec_int_pop(struct vec_int* vec)
{
    if (vec->len > 0) {
        vec->len -= 1;
    }
}

static inline void vec_int_push(struct vec_int* vec, int val)
{
    if (vec->len == vec->cap) {
        const size_t new_cap = max_usize(2 * vec->cap, 4);

        vec->ptr = (int*) realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        vec->cap = new_cap;
    }

    vec->ptr[vec->len] = val;
    vec->len += 1;
}

typedef struct {
    struct vec_int stack;
    struct vec_int min_stack;
} MinStack;


MinStack* minStackCreate()
{
    MinStack* init_res = (MinStack*) malloc(sizeof(MinStack));
    init_res->stack = vec_int_new();
    init_res->min_stack = vec_int_new();
    return init_res;
}

void minStackPush(MinStack* obj, int val)
{
    vec_int_push(&obj->stack, val);
    if (vec_int_is_empty(&obj->min_stack) || vec_int_top(&obj->min_stack) >= val) {
        vec_int_push(&obj->min_stack, val);
    }
}

void minStackPop(MinStack* obj)
{
    if (vec_int_is_empty(&obj->stack)) {
        return;
    }

    const int val = vec_int_top(&obj->stack);
    vec_int_pop(&obj->stack);

    if (!vec_int_is_empty(&obj->min_stack) && vec_int_top(&obj->min_stack) == val) {
        vec_int_pop(&obj->min_stack);
    }
}

int minStackTop(MinStack* obj)
{
    return vec_int_top(&obj->stack);
}

int minStackGetMin(MinStack* obj)
{
    return vec_int_top(&obj->min_stack); // min_stack is never empty when stack is non‑empty
}

void minStackFree(MinStack* obj)
{
    vec_int_free(&obj->stack);
    vec_int_free(&obj->min_stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
