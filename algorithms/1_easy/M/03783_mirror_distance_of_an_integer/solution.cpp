class Solution {
public:
    static int mirrorDistance(const int n) {
        int temp {n};
        int rev_n {0};

        while (temp > 0) {
            rev_n = rev_n * 10 + temp % 10;
            temp /= 10;
        }

        return abs(n - rev_n);
    }
};
