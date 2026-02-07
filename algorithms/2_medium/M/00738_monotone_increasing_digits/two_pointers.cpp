class Solution {
    static inline vector<int> get_digits(int n) {
        vector<int> digits;
        digits.reserve(10);

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        ranges::reverse(digits);

        return digits;
    }
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) {
            return n;
        }

        const vector<int> digits{ get_digits(n) };
        const size_t len{ digits.size() };
        int res{ 0 };
        size_t left{ 0 };
        size_t right{ 0 };

        while (right < len) {
            if (digits[right] == digits[left]) {
                right += 1;
            } else if (digits[right] > digits[left]) {
                while (left < right) {
                    res *= 10;
                    res += digits[left];
                    left += 1;
                }
            } else {
                res *= 10;
                res += digits[left] - 1;
                left += 1;

                while (left < len) {
                    res *= 10;
                    res += 9;
                    left += 1;
                }

                return res;
            }
        }

        // If 'right' reach end, then it means n has monotone increasing digits
        // So simply returning n is enough
        return n;
    }
};
