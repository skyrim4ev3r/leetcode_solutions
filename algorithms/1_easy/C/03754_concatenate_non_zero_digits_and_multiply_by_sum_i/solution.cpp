class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum{0};
        int p{1};
        int res{0};

        while (n / p >= 10) {
            p *= 10;
        }

        while (p > 0) {
            const int dig{(n / p) % 10};
            p /= 10;

            if (dig > 0) {
                res *= 10;
                res += dig;
                sum += dig;
            }
        }

        return static_cast<long long>(res) * static_cast<long long>(sum);
    }
};
