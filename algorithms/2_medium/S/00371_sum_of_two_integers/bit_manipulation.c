static inline unsigned int get_sum_helper(unsigned int a, unsigned int b)
{
    while (b != 0) {
        int new_b = (b & a) << 1;
        a = a ^ b;
        b = new_b;
    }

    return a;
}

int getSum(int a, int b)
{
    return (int)get_sum_helper((unsigned int)a, (unsigned int)b);
}
