static int* max_element(const int* arr, ptrdiff_t start, ptrdiff_t end)
{
    if (start >= end) {
        return NULL;
    }

    int* res = &arr[start];
    for (ptrdiff_t i = start; i < end; i += 1) {
        if (*res < arr[i]) {
            res = &arr[i];
        }
    }
    return res;
}

struct cell {
    int cost;
    int node;
};

struct vec_pair {
    struct cell* ptr;
    size_t len;
    size_t cap;
};

static inline struct cell cell_new(int cost, int node)
{
    struct cell new_cell = { cost: cost, node: node};
    return new_cell;
}

struct min_heap {
    struct cell* arr;
    size_t len;
    size_t cap;
};

static inline struct min_heap min_heap_with_cap(const size_t cap)
{
    struct cell* arr = malloc(cap * sizeof(*arr));
    assert(arr != NULL);
    struct min_heap new_heap = {
        arr: arr,
        len: 0,
        cap: cap
    };

    return new_heap;
}

static inline void min_heap_swap(struct min_heap* heap, ptrdiff_t i, ptrdiff_t j)
{
    struct cell temp = heap->arr[i];
    heap->arr[i] = heap->arr[j];
    heap->arr[j] = temp;
}

static inline bool min_heap_is_empty(struct min_heap* heap)
{
    return heap->len == 0;
}

void min_heap_inc_cap_auto(struct min_heap* heap)
{
    size_t new_cap = 2 * heap->cap;
    if (new_cap == 0) {
        new_cap = 1;
    }
    heap->arr = (struct cell*) realloc(heap->arr, new_cap * sizeof(struct cell));
    heap->cap = new_cap;
}

void heapify_up(struct min_heap* heap)
{
    ptrdiff_t i = (ptrdiff_t)(heap->len) - 1;
    struct cell* arr = heap->arr;
    while (i > 0) {
        ptrdiff_t parent = (i - 1) / 2;

        if (arr[parent].cost > arr[i].cost) {
            min_heap_swap(heap, parent, i);
            i = parent;
        } else {
            break;
        }
    }
}

void heapify_down(struct min_heap* heap)
{
    ptrdiff_t i = 0;
    struct cell* arr = heap->arr;
    const ptrdiff_t len = (ptrdiff_t)(heap->len);

    while (i < len) {
        ptrdiff_t left = (i * 2) + 1;
        ptrdiff_t right = (i * 2) + 2;

        if (left >= len) {
            return;
        } else if (right >= len) {
            if (arr[left].cost < arr[i].cost) {
                min_heap_swap(heap, left, i);
            }
            return;
        } else if (arr[left].cost < arr[i].cost || arr[right].cost < arr[i].cost) {
            if(arr[left].cost < arr[right].cost) {
                min_heap_swap(heap, left, i);
                i = left;
            } else {
                min_heap_swap(heap, right, i);
                i = right;
            }
        } else {
            return;
        }
    }
}

void min_heap_push(struct min_heap* heap, struct cell val)
{
    if (heap->len == heap->cap) {
        min_heap_inc_cap_auto(heap);
    }
    heap->arr[heap->len] = val;
    heap->len += 1;
    heapify_up(heap);
}

struct cell min_heap_pop(struct min_heap* heap)
{
    const ptrdiff_t last_idx = (ptrdiff_t)(heap->len) - 1;
    assert(last_idx >= 0);
    struct cell res = heap->arr[0];
    heap->arr[0] = heap->arr[last_idx];
    heap->len -= 1;
    heapify_down(heap);
    return res;
}

int networkDelayTime(int** times, int times_len_i32, int* times_cols_len, int n, int k)
{
    assert(times != NULL && times_cols_len != NULL && times_len_i32 > 0 && 
           times_cols_len[0] == 3 && n > 0 && k > 0 && k <= n);
    const ptrdiff_t times_len = times_len_i32;
    const ptrdiff_t n_isize = n;

    struct min_heap min_heap = min_heap_with_cap(2 * (size_t)n);
    struct vec_pair* adj = malloc((size_t)(n_isize + 1) * sizeof(*adj));
    for (ptrdiff_t i = 0; i <= n_isize; i += 1) {
        struct vec_pair* ptr = &adj[i];
        ptr->len = 0;
        ptr->cap = 0;
        ptr->ptr = NULL;
    }
    assert(adj != NULL);
    for (ptrdiff_t i = 0; i < times_len; i += 1) {
        const int* t = times[i];
        assert(t[0] > 0 && t[1] > 0);
        assert(t[0] <= n && t[1] <= n);
        assert(t[2] >= 0);
        struct vec_pair* curr_vec = &adj[t[0]];
        if (curr_vec->len == curr_vec->cap) {
            const size_t new_cap = curr_vec->cap == 0 ? 4 : 2 * curr_vec->cap;
            struct cell* ptr = realloc(curr_vec->ptr, new_cap * sizeof(*ptr));
            assert(ptr != NULL);
            curr_vec->cap = new_cap;
            curr_vec->ptr = ptr;
        }
        curr_vec->ptr[curr_vec->len].cost = t[2];
        curr_vec->ptr[curr_vec->len].node = t[1];
        curr_vec->len += 1;
    }
    int* costs = malloc(((size_t)n + 1) * sizeof(*costs));
    assert(costs != NULL);
    for (ptrdiff_t i = 0; i <= n_isize; i += 1) {
        costs[i] = INT_MAX;
    }
    min_heap_push(&min_heap, cell_new(0, k));

    while (!min_heap_is_empty(&min_heap)) {
        const struct cell cell = min_heap_pop(&min_heap);
        if (cell.cost > costs[cell.node]) {
            continue;
        }

        costs[cell.node] = cell.cost;

        struct vec_pair* curr_adj = &adj[cell.node];
        const ptrdiff_t curr_adj_len = (ptrdiff_t)(curr_adj->len);
        for (ptrdiff_t i = 0; i < curr_adj_len; i += 1) {
            const int new_path_cost = curr_adj->ptr[i].cost + cell.cost;
            const int other_node = curr_adj->ptr[i].node;

            if (new_path_cost < costs[other_node]) {
                costs[other_node] = new_path_cost;
                min_heap_push(&min_heap, cell_new(new_path_cost, other_node));
            }
        }
    }

    const int* res_ptr = max_element(costs, 1, n + 1);
    assert(res_ptr != NULL);
    const int res = *res_ptr;

/* cleanup: */
    free(min_heap.arr);
    for (ptrdiff_t i = 0; i <= n_isize; i += 1) {
        struct vec_pair* ptr = &adj[i];
        ptr->len = 0;
        ptr->cap = 0;
        free(ptr->ptr);
        ptr->ptr = NULL;
    }
    free(adj);
    free(costs);
    return res == INT_MAX ? -1 : res;
}
