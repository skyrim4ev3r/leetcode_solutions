static inline int gcd(int a, int b)
{
    while (b != 0) {
        const int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

bool canMeasureWater(int x, int y, int target)
{
    return target <= x + y && target % gcd(x, y) == 0;
}
