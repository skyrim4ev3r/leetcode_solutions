bool isUgly(int n)
{
    if (n <= 0) {
        return false;
    }

    const int arr[3] = {2, 3, 5};

    for (ptrdiff_t i = 0; i < 3; i += 1) {
        while (n % arr[i] == 0) {
            n /= arr[i];
        }
    }

    return n == 1;
}
