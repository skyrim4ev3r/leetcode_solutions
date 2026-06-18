class Solution {
public:
    static int sumOfGoodIntegers(const int n, const int k) {
        int sum = 0;

        for (int x = std::max(n - k, 1); x <= n + k; x += 1) {
            if ((x & n) == 0) {
                sum += x;
            }
        }

        return sum;
    }
};
