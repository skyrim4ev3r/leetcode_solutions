bool isPerfectSquare(int num_i32)
{
    assert(num_i32 > 0);
    const int64_t num = num_i32;
    int64_t hi = num;
    int64_t lo = 1;

    while (lo <= hi) {
        int64_t mid = lo + (hi - lo) / 2;
        int64_t square_mid = mid * mid;

        if (square_mid == num) {
            return true;
        }

        if (square_mid < num) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}
