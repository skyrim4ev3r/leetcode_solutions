static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int countNumbersWithUniqueDigits(int n)
{
    assert(n >= 0);
    int count = 1; // for n = 0
    int ways = 9;

    for (int i = 1; i <= n; i += 1) {
        count += ways;
        ways *= max_int(0, 10 - i);
    }

    return count;
}
