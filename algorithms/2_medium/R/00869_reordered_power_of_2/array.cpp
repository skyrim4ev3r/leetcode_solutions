const size_t VALID_BITS_COUNT{ 31 };

class Solution {
    static inline array<uint8_t, 10> get_digits_freqs(int n){
        array<uint8_t, 10> res{};

        while (n > 0) {
            res[static_cast<size_t>(n % 10)] += 1;
            n /= 10;
        }

        return res;
    }
public:
    static bool reorderedPowerOf2(int n) {
        const auto digits_freqs_n{ get_digits_freqs(n) };

        for (size_t i{ 0 }; i < VALID_BITS_COUNT; ++i) {
            const auto digits_freqs_power_of_two{ get_digits_freqs(1 << i) };

            if (digits_freqs_n == digits_freqs_power_of_two) {
                return true;
            }
        }

        return false;
    }
};
