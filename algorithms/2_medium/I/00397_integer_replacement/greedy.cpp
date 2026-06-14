class Solution {
public:
    int integerReplacement(int n_i32) {
        assert(n_i32 > 0);
        int64_t n = n_i32;
        int steps = 0;

        while (n != 1) {
            if ((n & 1) == 0) {
                n /= 2;
            } else if (n != 3 && (n & 3) == 3) {
                n += 1;
            } else {
                n -= 1;
            }

            steps += 1;
        }

        return steps;
    }
};
