static inline int largest_proper_divisor(const int n)
{
    const int n_sqrt = (int) sqrt(n); 
    for (int i = 2; i <= n_sqrt; i += 1) {
        if (n % i == 0) {
            return n / i;
        }
    }

    return 1;
}

int minSteps(int n)
{
    assert(n > 0);
    int cnt = 0;

    while (n > 1) {
        const int lpd = largest_proper_divisor(n);
        cnt += n / lpd;
        n = lpd;
    }

    return cnt;
}
