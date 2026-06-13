class Solution {
    static int ipow(const int base, const int exp) {
        if (exp == 0) { 
            return 1 ;
        }

        const int result = ipow(base, exp >> 1);

        if ((exp & 1) == 1) {
            return result * result * base;
        }

        return result * result;
    }
public:
    int integerBreak(int n) {
        assert(n >= 2 && n <= 58);
        if (n == 2) {
            return 1;
        }

        if (n == 3) {
            return 2;
        }

        int count_two = 0;
        int count_three = n / 3;
        int remainder = n % 3;

        if (remainder == 1) {
            count_two = 2;
            count_three -= 1;
        } else if (remainder == 2) {
            count_two = 1;
        }

        return ipow(3, count_three) * ipow(2, count_two);
    }
};
