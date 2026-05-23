class Solution {
public:
    int myAtoi(string s) {
        const size_t len = s.size();
        bool is_negative = false;
        size_t index = 0;

        while (index < len &&  s[index] == ' ') {
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

        int64_t res = 0;

        while (index < len && s[index] >= '0' && s[index] <= '9') {
            res *= 10;
            res += s[index] - '0';
            index += 1;

            if (is_negative && (res * -1 < numeric_limits<int32_t>::min())) {
                return numeric_limits<int32_t>::min();
            }

            if (!is_negative && res > numeric_limits<int32_t>::max()) {
                return numeric_limits<int32_t>::max();
            }
        }

        if (is_negative) {
            res *= -1;
        }

        return static_cast<int>(res);
    }
};
