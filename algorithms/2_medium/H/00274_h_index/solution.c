static inline int cmp(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*) a_ptr;
    const int b = *(int*) b_ptr;

    return (a < b) - (a > b);
}

int hIndex(int* citations, int citations_size)
{
    assert(citations != NULL && citations_size > 0);
    const ptrdiff_t len = citations_size;
    qsort(citations, (size_t) len, sizeof(*citations), cmp);
    int res = 0;

    for (ptrdiff_t i = 0; i < len; ++i) {
        const int count = (int) i + 1;

        if (citations[i] >= count) {
            res = count;
        } else {
            break;
        }
    }

    return res;
}
