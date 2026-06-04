static inline int calc_wave_num(int n)
{
    if (n < 100) {
        return 0;
    }

    int count = 0;

    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;
    n /= 10;

    while(true) {
        if ((b > a && b > c) || (b < a && b < c)) {
            count += 1;
        }

        if (n == 0) { 
            break;
        }

        c = b;
        b = a;
        a = n % 10;
        n /= 10;
    }

    return count;
}

int totalWaviness(int num1, int num2)
{
    int count = 0;

    for (int i = num1; i <= num2; i += 1) {
        count += calc_wave_num(i);
    }

    return count;
}
