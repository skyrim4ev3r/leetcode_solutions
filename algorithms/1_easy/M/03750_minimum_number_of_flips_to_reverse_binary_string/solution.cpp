class Solution {
public:
    static int minimumFlips(int n) {
        int rev{0};
        int temp{n};

        while (temp > 0) {
            rev = rev << 1;

            if ( (temp & 1) == 1 ) {
                rev |= 1;
            }

            temp = temp >> 1;
        }

        return __builtin_popcount(rev ^ n);
    }
};
