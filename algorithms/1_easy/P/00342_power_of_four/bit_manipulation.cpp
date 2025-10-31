class Solution {
public:
    bool isPowerOfFour(int n) {

         if (__builtin_popcount(n) != 1) {
            return false;
        }

        for (int i{0}; i < 32; ++i) {
            if ((n & (1 << i)) != 0) {
                return (i & 1) == 0;
            }
        }

        return false;
    }
};
