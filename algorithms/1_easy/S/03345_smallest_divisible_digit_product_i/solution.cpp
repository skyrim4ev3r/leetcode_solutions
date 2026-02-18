class Solution {
    static inline int32_t calc_product_digits(int32_t n) {
        int32_t res{ 1 };

        while (n > 0) {
            res = res * (n % 10);
            n /= 10;
        }

        return res;
    }
public:
    static int32_t smallestNumber(int32_t n, int32_t t) {
        // In every 10 consecutive numbers, at least one has the digit 0,
        // ensuring a product of 0, which satisfies the condition 0 % t == 0.
        for (int32_t i{ n }; i < n + 10; ++i) {
            const int32_t product_digits{ calc_product_digits(i) };

            if (product_digits % t == 0) {
                return i;
            }
        }

        throw std::runtime_error("Unreachable code executed");
    }
};
