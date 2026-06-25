struct data {
    int start;
    int end;
    int tip;
};

static inline int64_t max_i64(const int64_t a, const int64_t b)
{
    return a > b ? a : b;
}

static int cmp(const void* a_ptr, const void* b_ptr)
{
    const struct data* a = a_ptr;
    const struct data* b = b_ptr;
    return (a->start > b->start) - (a->start < b->start);
}

long long maxTaxiEarnings(int n, int** rides, int rides_size, int* rides_col_cize)
{
    assert(n > 0 && n < INT_MAX && rides != NULL && rides_size > 0 && rides_col_cize != NULL && rides_col_cize[0] == 3);
    int64_t* best_ending_at = calloc((size_t)n + 1, sizeof(*best_ending_at));
    struct data* adj = malloc((size_t)rides_size * sizeof(*adj));
    assert(best_ending_at != NULL && adj != NULL);

    for (int i = 0; i < rides_size; i += 1) {
        adj[i] = (struct data) { start: rides[i][0], end: rides[i][1], tip: rides[i][2] };
    }

    qsort(adj, (size_t)rides_size, sizeof(*adj), cmp);

    int64_t global_best_so_far = 0;
    int adj_idx = 0;
    for (int i = 1; i <= n; i += 1) {
        global_best_so_far = max_i64(global_best_so_far, best_ending_at[i]);

        while (adj_idx < rides_size && adj[adj_idx].start == i) {
            const int end = adj[adj_idx].end;
            const int tip = adj[adj_idx].tip;
            adj_idx += 1;

            int64_t ride_earnings = (end - i) + tip;
            int64_t new_profit = global_best_so_far + ride_earnings;
            best_ending_at[end] = max_i64(best_ending_at[end], new_profit);
        }
    }

/* cleanup: */
    free(adj);
    free(best_ending_at);
    return global_best_so_far;
}
