class Solution {
public:
    int countPrimes(int n_i32) {
        if (n_i32 < 3) {
            return 0;
        }
        
        const size_t n = static_cast<size_t>(n_i32);
        auto is_prime = vector<bool>(n, true);
        is_prime[0] = false;
        is_prime[1] = false;
        const size_t ceil_sqrt_n = static_cast<size_t>(std::ceil(std::sqrt(static_cast<double>(n))));
        
        for (size_t i = 0; i <= ceil_sqrt_n; i += 1) {
            if (is_prime[i]) {
                for (size_t j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        return static_cast<int>(std::count(is_prime.begin(), is_prime.end(), true));
    }
};
