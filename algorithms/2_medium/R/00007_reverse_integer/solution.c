int reverse(const int x)
{
    const bool is_negative = x < 0;
    int64_t rev = 0;
    int64_t temp = is_negative ? ((int64_t) x) * -1: x;

    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (is_negative) {
        rev *= -1;
    }

    if (rev > INT32_MAX || rev < INT32_MIN) {
        return 0;
    }

    return (int) rev;
}
