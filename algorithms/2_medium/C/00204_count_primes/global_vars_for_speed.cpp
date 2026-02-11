const size_t MAX_N{ 5'000'001 };
array<bool, MAX_N> is_prime;
array<int, MAX_N> prefix_count;
bool should_init_array{ true };

class Solution {
public:
    Solution() {
        if (should_init_array) {
            for (auto& p : is_prime) {
                p = true;
            }

            for (auto& c : prefix_count) {
                c = 0;
            }

            is_prime[0] = false;
            is_prime[1] = false;

            const size_t ceil_sqrt_max_n{ static_cast<size_t>(ceil(sqrt(MAX_N))) };

            for (size_t i{ 0 }; i <= ceil_sqrt_max_n; ++i) {
                if (is_prime[i]) {
                    for (size_t j{ i * 2 }; j < MAX_N; j += i) {
                        is_prime[j] = false;
                    }
                }
            }
            for (size_t i{ 1 }; i < MAX_N; ++i) {
                prefix_count[i] = prefix_count[i - 1] + (is_prime[i - 1] ? 1 : 0);
            }

            should_init_array = false;
        }
    }

    int countPrimes(int n) {
        return prefix_count[static_cast<size_t>(n)];
    }
};
