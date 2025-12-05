class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int new_b = (b & a) << 1;
            a = a ^ b;
            b = new_b;
        }

        return a;
    }
};
