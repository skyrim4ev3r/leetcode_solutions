class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        const size_t n_usize{ static_cast<size_t>(n) };
        vector<bool> is_prime(n_usize, true);
        is_prime[0] = false;
        is_prime[1] = false;
        const size_t ceil_sqrt_n{ static_cast<size_t>(ceil(sqrt(n))) };

        for (size_t i{ 0 }; i <= ceil_sqrt_n; ++i) {
            if (is_prime[i]) {
                for (size_t j{ i * 2 }; j < n_usize; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        return static_cast<int>(count(is_prime.begin(), is_prime.end(), true));
    }
};
