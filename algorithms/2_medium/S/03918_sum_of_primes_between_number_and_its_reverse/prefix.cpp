constexpr int max_n = 1000;
static int primes[max_n + 1];
static pthread_once_t flag = PTHREAD_ONCE_INIT;

static void build_primes() {
    for (int i = 2; i <= max_n; i += 1) { primes[i] = 1; }
    primes[0] = 0;
    primes[1] = 0;

    const int sq = static_cast<int>(sqrt(max_n + 1));
    for (int i = 2; i <= sq; i += 1) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= max_n; j += i) {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i <= max_n; i += 1) {
        if (primes[i] == 1) {
            primes[i] = i;
        }

        primes[i] += primes[i - 1];
    }
}

class Solution {
    static int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
public:
    static int sumOfPrimesInRange(int n) {
        assert(n >= 1 && n <= 1000);
        pthread_once(&flag, build_primes);
        const int rev = reverse(n);
        const int min = std::min(n, rev);
        const int max = std::max(n, rev);

        return primes[max]- primes[min - 1];
    }
};
