int compare(const void* a_ptr, const void* b_ptr)
{
    const int a = *(int*) a_ptr;
    const int b = *(int*) b_ptr;
    return (a > b) - (a < b);
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize)
{
    const size_t len = asteroidsSize;
    qsort((void*) asteroids, len, sizeof(*asteroids), compare);
    int64_t curr_mass = mass;

    for (size_t i = 0; i < len; i += 1) {
        if (asteroids[i] > curr_mass) {
            return false;
        }

        curr_mass += asteroids[i];
    }

    return true;
}
