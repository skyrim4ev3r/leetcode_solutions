struct cell {
    int cost;
    size_t i;
    size_t j;
};

static inline struct cell cell_new(int cost, size_t i, size_t j)
{
    struct cell new_cell = {
        cost: cost,
        i: i,
        j: j
    };

    return new_cell;
}

struct min_heap {
    struct cell* arr;
    size_t len;
    size_t capacity;
};

static inline struct min_heap min_heap_new()
{
    struct min_heap new_heap = {
        arr: NULL,
        len: 0,
        capacity: 0
    };

    return new_heap;
}

static inline void min_heap_swap(struct min_heap* heap, size_t i, size_t j)
{
    struct cell temp = heap->arr[i];
    heap->arr[i] = heap->arr[j];
    heap->arr[j] = temp;
}

static inline bool min_heap_empty(struct min_heap* heap)
{
    return heap->len == 0;
}

void min_heap_increase_capacity_auto(struct min_heap* heap)
{
    size_t new_capacity = 2 * heap->capacity;
    if (new_capacity == 0) {
        new_capacity = 1;
    }
    heap->arr = (struct cell*) realloc(heap->arr, new_capacity * sizeof(struct cell));
    heap->capacity = new_capacity;
}

void heapify_up(struct min_heap* heap)
{
    size_t i = heap->len - 1;
    struct cell* arr = heap->arr;
    while (i > 0) {
        size_t parent = 0;
        if ((i & 1) == 1) {
            parent = i / 2;
        } else {
            parent = (i - 2) / 2;
        }

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
    size_t i = 0;
    struct cell* arr = heap->arr;
    const size_t len = heap->len;

    while (i < len) {
        size_t left = (i * 2) + 1;
        size_t right = (i * 2) + 2;

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
    if (heap->len == heap->capacity) {
        min_heap_increase_capacity_auto(heap);
    }
    heap->arr[heap->len] = val;
    heap->len += 1;
    heapify_up(heap);
}

struct cell min_heap_pop(struct min_heap* heap)
{
    struct cell res = heap->arr[0];
    heap->arr[0] = heap->arr[heap->len - 1];
    heap->len -= 1;
    heapify_down(heap);
    return res;
}

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    const size_t rows = gridSize;
    const size_t cols = gridColSize[0];
    int result = -1;

    if (rows == 1 && cols == 1) {
        return grid[0][0];
    }

    struct min_heap heap = min_heap_new();
    bool (*is_visited)[cols] = (bool (*)[cols]) malloc(rows * cols * sizeof(bool));
    memset(is_visited, 0, rows * cols);
    static const size_t directions[2][2] = {{0, 1}, {1, 0}};

    min_heap_push(&heap, cell_new(grid[0][0], 0, 0));
    is_visited[0][0] = true;

    while (!min_heap_empty(&heap)) {
        struct cell top = min_heap_pop(&heap);

        for (size_t d_index = 0; d_index < 2; d_index += 1) {
            const size_t new_i = top.i + directions[d_index][0];
            const size_t new_j = top.j + directions[d_index][1];

            if (new_j >= cols || new_i >= rows || is_visited[new_i][new_j]) {
                continue;
            }

            is_visited[new_i][new_j] = true;
            const int new_cost = grid[new_i][new_j] + top.cost;

            if (new_i == rows - 1 && new_j == cols - 1) {
                result = new_cost;
                goto cleanup;
            }

            min_heap_push(&heap, cell_new(new_cost, new_i, new_j));
        }
    }
cleanup:
    free(is_visited);
    free(heap.arr);
    return result;
}
