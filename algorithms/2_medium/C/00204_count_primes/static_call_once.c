#include <threads.h>
#define  MAX_INPUT_SIZE 5000001

static once_flag prefix_primes_init_flag = ONCE_FLAG_INIT;
static int prefix_primes[MAX_INPUT_SIZE];

static inline void init_prefix_primes()
{
    for (size_t i = 0; i < MAX_INPUT_SIZE; i += 1) {
        prefix_primes[i] = 1;
    }
    prefix_primes[0] = 0;
    prefix_primes[1] = 0;

    const size_t ceil_sqrt_max_n = (size_t) ceil(sqrt((double) MAX_INPUT_SIZE));

    for (size_t i = 0; i <= ceil_sqrt_max_n; i += 1) {
        if (prefix_primes[i] == 1) {
            for (size_t j = i * i; j < MAX_INPUT_SIZE; j += i) {
                prefix_primes[j] = 0;
            }
        }
    }

    int prev_is_prime =  0;

    for (size_t i = 1; i < MAX_INPUT_SIZE; i += 1) {
        const int curr_is_prime = prefix_primes[i];
        prefix_primes[i] = prefix_primes[i - 1] + prev_is_prime;
        prev_is_prime = curr_is_prime;
    }
}

int countPrimes(int n)
{
    call_once(&prefix_primes_init_flag, init_prefix_primes);
    return prefix_primes[(size_t) n];
}
