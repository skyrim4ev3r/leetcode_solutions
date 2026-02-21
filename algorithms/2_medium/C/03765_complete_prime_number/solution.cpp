class Solution {
    static inline bool is_prime(const int num) {
        if (num == 2) {
            return true;
        }

        if (num <= 1 || num % 2 == 0) {
            return false;
        }

        const int sqrt_num = sqrt(num);

        for (int i{ 3 }; i <= sqrt_num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    static inline bool check_prefix(const int num) {
        int prefix{ num };
        while (prefix > 0) {
            if (!is_prime(prefix)) {
                return false;
            }

            prefix /= 10;
        }
        return true;
    }

    static inline bool check_suffix(const int num) {
        int suffix{ num };
        int p{ 1 };

        while (suffix / p >= 10) {
            p *= 10;
        }

        while (suffix > 0) {
            if (!is_prime(suffix)) {
                return false;
            }

            suffix = suffix - (suffix / p) * p;
            p /= 10;
        }

        return true;
    }
public:
    bool completePrime(int num) {
        return check_prefix(num) && check_suffix(num);
    }
};
