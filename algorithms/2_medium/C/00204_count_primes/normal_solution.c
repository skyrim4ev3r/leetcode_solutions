static inline size_t count_bool(const bool* arr, const size_t len, const bool target)
{
    size_t count = 0;

    for (size_t i = 0; i < len; i += 1) {
        count += (size_t) (arr[i] == target);
    }

    return count;
}

int countPrimes(int n_i32)
{
    if (n_i32 < 3) {
        return 0;
    }

    const size_t n = (size_t) n_i32;
    bool* is_prime = malloc(n * sizeof(*is_prime));
    for (size_t i = 0; i < n; i += 1) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    const size_t ceil_sqrt_n = (size_t) ceil(sqrt((double) n));

    for (size_t i = 0; i <= ceil_sqrt_n; i += 1) {
        if (is_prime[i]) {
            for (size_t j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    const size_t res = count_bool(is_prime, n, true);
cleanup:
    free(is_prime);
    return (int) res;
}
