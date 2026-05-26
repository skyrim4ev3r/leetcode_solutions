int climbStairs(int n)
{
    if (n <= 2) {
        return n;
    }

    int prev_prev = 1;
    int prev = 2;
    int curr = 0;

    for (int i = 3; i <= n; i += 1) {
        curr = prev + prev_prev;
        prev_prev = prev;
        prev = curr;
    }

    return curr;
}
