int addDigits(int num)
{
    assert(num >= 0);
    if (num == 0) {
        return 0;
    }

    const int res = num % 9;
    return res == 0 ? 9 : res;
}
