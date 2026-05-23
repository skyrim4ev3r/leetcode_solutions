class Solution {
public:
    static int reverse(const int x) {
        int64_t rev = 0;
        int64_t temp = abs(static_cast<int64_t>(x));

        while (temp != 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        if (x < 0) {
            rev *= -1;
        }

        if (rev > numeric_limits<int32_t>::max() || rev < numeric_limits<int32_t>::min()) {
            return 0;
        }

        return static_cast<int>(rev);
    }
};
