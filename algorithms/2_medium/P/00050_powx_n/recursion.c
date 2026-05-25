static double pow_recursion(double x, int64_t n)
{
    if (n == 0) {
        return 1;
    }

    const double res = pow_recursion(x, n / 2);

    if ((n & 1) == 1) {
        return res * res * x;
    } else {
        return res * res;
    }
}

double myPow(double x, int n)
{
    const int64_t pow_positive = n < 0 ? -((int64_t) n) : n;
    const double res = pow_recursion(x, pow_positive);
    return n < 0 ? 1 / res : res;
}
