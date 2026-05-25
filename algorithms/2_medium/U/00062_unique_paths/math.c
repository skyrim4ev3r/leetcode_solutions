int uniquePaths(int m, int n)
{
    int64_t max = m > n ? m - 1 : n - 1;
    int64_t min = m > n ? n - 1 : m - 1;
    int64_t high = max + min;
    int64_t sum = 1;

    for (int64_t k = max + 1; k <= high; k += 1) {
        sum *= k;

        while (min > 1 && sum % min == 0) {
            sum /= min;
            min -= 1;
        }
    }

    return (int) sum;
}
