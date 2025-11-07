class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum{0};
        int mul{1};

        while (n > 0) {
            int tmp = n % 10;
            mul *= tmp;
            sum += tmp;
            n /= 10;
        }

        return mul - sum;
    }
};
