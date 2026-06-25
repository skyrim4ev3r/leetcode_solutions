#define MAX_N 1000
static int primes[MAX_N + 1];
static pthread_once_t flag = PTHREAD_ONCE_INIT;

static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static void build_primes()
{
    for (int i = 2; i <= MAX_N; i += 1) { primes[i] = 1; }
    primes[0] = 0;
    primes[1] = 0;

    const int sq = (int)sqrt((double)(MAX_N + 1));
    for (int i = 2; i <= sq; i += 1) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= MAX_N; j += i) {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i <= MAX_N; i += 1) {
        if (primes[i] == 1) {
            primes[i] = i;
        }

        primes[i] += primes[i - 1];
    }
}

static int reverse(int n)
{
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int sumOfPrimesInRange(int n)
{
    assert(n >= 1 && n <= 1000);
    pthread_once(&flag, build_primes);
    const int rev = reverse(n);
    const int min = min_int(n, rev);
    const int max = max_int(n, rev);

    return primes[max]- primes[min - 1];
}
