class Solution {
    static inline long long calc_final_res_len(const string& s) {
        long long res_len = 0;

        for (const char ch : s) {
            if (ch == '#') {
                res_len *= 2;
            } else if (ch >= 'a' && ch  <= 'z') {
                res_len += 1;
            } else if (ch == '*') {
                res_len = std::max(0LL, res_len - 1);
            }
        }

        return res_len;
    }
public:
    static char processStr(const string& s, long long k) {
        assert(k >= 0);
        long long res_len = calc_final_res_len(s);
        if (res_len <= k) {
            return '.';
        }

        for (ptrdiff_t i = std::ssize(s) - 1; i >= 0; i -= 1) {
            const char ch = s[i];

            if (ch == '#') {
                res_len /= 2;
                if (k >= res_len) {
                    k -= res_len;
                }
            } else if (ch >= 'a' && ch  <= 'z') {
                res_len -= 1;
                if (res_len == k) {
                    return ch;
                }
            } else if (ch == '*') {
                res_len += 1;
            } else if (ch == '%') {
                k = res_len - k - 1;
            } else {
                cerr << "invalid input";
                abort();
            }
        }

        return '.';
    }
};
