int trailingZeroes(int n)
{
    int cnt_five = 0;

    for (int div = 5; div <= n; div *= 5) {
        cnt_five += n / div;
    }

    return cnt_five;
}
