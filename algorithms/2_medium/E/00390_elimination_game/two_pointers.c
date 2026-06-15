int lastRemaining(int n)
{
    assert(n >= 1);
    int hi = n;
    int lo = 1;
    int steps = 1;
    bool lo_to_hi = true;

    while (lo < hi) {
        const int cnt = ((hi - lo + 1) + (steps - 1)) / steps;

        if (lo_to_hi) {
            lo += steps;
            if ((cnt & 1) == 1) {
                hi -= steps;
            }
        } else {
            hi -= steps;
            if ((cnt & 1) == 1) {
                lo += steps;
            }
        }

        steps *= 2;
        lo_to_hi = !lo_to_hi;
    }

    return lo;
}
