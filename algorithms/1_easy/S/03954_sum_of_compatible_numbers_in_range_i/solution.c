static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int sumOfGoodIntegers(int n, int k)
{
    int sum = 0;

    for (int x = max_int(n - k, 1); x <= n + k; x += 1) {
        if ((x & n) == 0) {
            sum += x;
        }
    }

    return sum;
}
