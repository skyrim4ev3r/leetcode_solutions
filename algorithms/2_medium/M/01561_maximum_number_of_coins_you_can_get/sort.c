static int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;
    return (a > b) - (a < b);
}

int maxCoins(int* piles, int len)
{
    assert(piles != NULL && len > 0 && len % 3 == 0);
    qsort(piles, (size_t)len, sizeof(*piles), cmp);

    int j = len - 2;
    int i = 0;
    int amount = 0;

    while (i < j) {
        amount += piles[j];
        j -= 2;
        i += 1;
    }

    return amount;
}
