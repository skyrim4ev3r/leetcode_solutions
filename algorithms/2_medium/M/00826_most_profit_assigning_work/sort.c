struct entity {
    int difficulty;
    int profit;
};

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int cmp_entity(const void* a_ptr, const void* b_ptr)
{
    const int a = ((struct entity*)a_ptr)->difficulty;
    const int b = ((struct entity*)b_ptr)->difficulty;
    return (a > b) - (a < b);
}

static int cmp_int(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

int maxProfitAssignment(int* difficulty, int difficulty_len, 
                        int* profit, int profit_len, 
                        int* worker, int worker_len)
{
    assert(difficulty != NULL && difficulty_len >= 0 &&
           profit != NULL && profit_len >= 0 &&
           worker != NULL && worker_len >= 0 &&
           difficulty_len == profit_len);

    const int jobs_len = difficulty_len;
    struct entity* jobs = malloc((size_t)jobs_len * sizeof(*jobs));
    assert(jobs != NULL);
    for (int i = 0; i < jobs_len; i += 1) {
        jobs[i] = (struct entity){ difficulty: difficulty[i], profit: profit[i]};
    }
    qsort(jobs, (size_t)jobs_len, sizeof(*jobs), cmp_entity);
    qsort(worker, (size_t)worker_len, sizeof(*worker), cmp_int);

    int res = 0;
    int max_profit = 0;
    int jobs_idx = 0;

    for (int i = 0; i < worker_len; i += 1) {
        while (jobs_idx < jobs_len && jobs[jobs_idx].difficulty <= worker[i]) {
            max_profit = max_int(max_profit, jobs[jobs_idx].profit);
            jobs_idx += 1;
        }

        res += max_profit;
    }

/* cleanup:*/
    free(jobs);
    return res;
}
