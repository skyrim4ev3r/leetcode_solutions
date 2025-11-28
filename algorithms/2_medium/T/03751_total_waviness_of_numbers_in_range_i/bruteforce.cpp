class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<int> digits;
        digits.reserve(6);
        int count{0};

        for (int i{num1}; i <= num2; ++i) {
            int temp{i};
            digits.clear();

            while (temp > 0) {
                digits.push_back(temp % 10);
                temp /= 10;
            }

            const size_t len{digits.size()};
            for (size_t i{1}; i + 1 < len; ++i) {
                if (
                    (digits[i] > digits[i - 1] && digits[i] > digits[i + 1]) ||
                    (digits[i] < digits[i - 1] && digits[i] < digits[i + 1])
                ) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
