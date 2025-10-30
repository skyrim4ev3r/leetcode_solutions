class Solution {
    double my_pow_helper(double x, long n) {
        if (n == 1) {
            return x;
        }

        double pow{my_pow_helper(x, n / 2)};

        pow *= pow;

        if (n % 2 == 1) {
            pow *= x;
        }

        return pow;
    }

public:
    double myPow(double x, int n) {

        if (n == 0) {
            return 1;
        }

        long n_i64{static_cast<long>(n)};

        if (n_i64 < 0) {
            return 1 / my_pow_helper(x, abs(n_i64));
        }

        return my_pow_helper(x, n_i64);
    }
};
