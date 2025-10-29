class Solution {
public:
    int reverse(int x) {

        long rev{0};
        long x_abs_i64{abs(static_cast<long>(x))};

        while (x_abs_i64 != 0) {
            rev = rev * 10 + x_abs_i64 % 10;
            x_abs_i64 /= 10;
        }

        if (x < 0) {
            rev *= -1;
        }

        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }

        return static_cast<int>(rev);
    }
};
