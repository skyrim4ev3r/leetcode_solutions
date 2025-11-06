class Solution {
public:
    int getLucky(string s, int k) {
        int sum{0};

        for (const char &ch: s) {
            int num{static_cast<int>(ch - 'a' + 1)};
            sum += num % 10 + num / 10;
        }

        for (int i{1}; i < k; ++i) {
            int tmp{0};

            while (sum > 0) {
                tmp += sum % 10;
                sum /= 10;
            }

            sum = tmp;
        }

        return sum;
    }
};
