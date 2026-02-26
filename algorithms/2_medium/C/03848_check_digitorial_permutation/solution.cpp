class Solution {
    static inline int calc_sum_fact_digit(int n) {
        array<int, 10> facts{};
        facts[0] = 1;
        for (size_t i{ 1 }; i < 10; ++i) {
            facts[i] = static_cast<int>(i) * facts[i - 1];
        }

        int sum{ 0 };

        while (n > 0) {
            sum += facts[static_cast<size_t>(n % 10)];
            n /= 10;
        }

        return sum;
    }

    static inline array<int, 10> calac_freqs_digits(int n) {
        array<int, 10> freqs{};
        while (n > 0) {
            freqs[static_cast<size_t>(n % 10)] += 1;
            n /= 10;
        }
        return freqs;
    }
public:
    static bool isDigitorialPermutation(const int n) {
        const int sum_fact_digit{ calc_sum_fact_digit(n) };

        return calac_freqs_digits(n) == calac_freqs_digits(sum_fact_digit);
    }
};
