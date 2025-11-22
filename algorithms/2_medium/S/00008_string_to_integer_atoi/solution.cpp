class Solution {
public:
    int myAtoi(string s) {
        const size_t len{s.size()};
        bool is_negative{false};
        size_t index{0};
        const long long INT_MIN_AS_i64{static_cast<long long>(numeric_limits<int>::min())};
        const long long INT_MAX_AS_i64{static_cast<long long>(numeric_limits<int>::max())};

        while (index < len && s[index] == ' ') {
            index += 1;
        }

        if (index == len) {
            return 0;
        }

        if (s[index] == '-') {
            is_negative = true;
        }

        if (s[index] == '-' || s[index] == '+') {
            index += 1;
        }

        long long res{0};

        while (index < len && s[index] >= '0' && s[index] <= '9') {
            res *= 10;
            res += static_cast<long long>(s[index] - '0');
            index += 1;

            if (is_negative && res * -1 < INT_MIN_AS_i64) {
                return numeric_limits<int>::min();
            }

            if (!is_negative && res > INT_MAX_AS_i64) {
                return numeric_limits<int>::max();
            }
        }

        if (is_negative) {
            return static_cast<int>(res * -1);
        }

        return static_cast<int>(res);
    }
};
