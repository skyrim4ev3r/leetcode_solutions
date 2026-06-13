class Solution {
    static inline unsigned int get_sum_helper(unsigned int a, unsigned int b) {
        while (b != 0) {
            int new_b = (b & a) << 1;
            a = a ^ b;
            b = new_b;
        }

        return a;
    }
public:
    static int getSum(int a, int b) {
        return static_cast<int>(get_sum_helper(static_cast<unsigned int>(a), static_cast<unsigned int>(b)));
    }
};
