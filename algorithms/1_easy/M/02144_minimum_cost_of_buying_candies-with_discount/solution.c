int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int *) a_ptr;
    const int b = *(int *) b_ptr;
    return (a < b) - (a > b);
}

int minimumCost(int* cost, int costSize)
{
    const size_t len = (size_t) costSize;
    int total_cost = 0;

    qsort(cost, len, sizeof(*cost), cmp);

    for (size_t i = 0; i < len; i += 3) {
        total_cost += cost[i] + (i + 1 < len ? cost[i + 1] : 0);
    }

    return total_cost;
}
