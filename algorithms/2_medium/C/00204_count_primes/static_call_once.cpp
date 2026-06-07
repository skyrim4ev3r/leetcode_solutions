constexpr size_t max_input_size = 5'000'001;
static std::once_flag prefix_primes_init_flag;
static int prefix_primes[max_input_size];

static void init_prefix_primes() noexcept {
    for (size_t i = 0; i < max_input_size; i += 1) {
        prefix_primes[i] = 1;
    }
    prefix_primes[0] = 0;
    prefix_primes[1] = 0;
    
    const size_t ceil_sqrt_max_n = static_cast<size_t>(std::ceil(std::sqrt(static_cast<double>(max_input_size))));
    
    for (size_t i = 0; i <= ceil_sqrt_max_n; i += 1) {
        if (prefix_primes[i] == 1) {
            for (size_t j = i * i; j < max_input_size; j += i) {
                prefix_primes[j] = 0;
            }
        }
    }
    
    int prev_is_prime =  0;
    
    for (size_t i = 1; i < max_input_size; i += 1) {
        const int curr_is_prime = prefix_primes[i];
        prefix_primes[i] = prefix_primes[i - 1] + prev_is_prime;
        prev_is_prime = curr_is_prime;
    }
}

class Solution {
public:
    static int countPrimes(int n) {
        std::call_once(prefix_primes_init_flag, init_prefix_primes);
        return prefix_primes[static_cast<size_t>(n)];
    }
};
