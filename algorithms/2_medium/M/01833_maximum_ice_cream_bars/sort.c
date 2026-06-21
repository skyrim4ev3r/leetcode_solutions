typedef ptrdiff_t isize;

int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;
    return (a > b) - (a < b);
}

int maxIceCream(int* costs, int costs_size, int coins)
{
    assert(costs != NULL && costs_size > 0 && coins > 0);
    const isize len = costs_size;
    qsort(costs, (size_t)len, sizeof(*costs), cmp);
    int cnt = 0;

    for (isize i = 0; i < len; i += 1) {
        if (coins >= costs[i]) {
            coins -= costs[i];
            cnt += 1;
        } else {
            break;
        }
    }

    return cnt;
}
