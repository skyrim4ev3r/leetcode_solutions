typedef ptrdiff_t isize;

class Solution {
    static int calc_len_palindrome(const string& s, const isize len, isize lo, isize hi) {
        if (lo < 0 || hi >= len || s[lo] != s[hi]) {
            return 0;
        }

        while (lo >= 0 && hi < len && s[lo] == s[hi]) {
            lo -= 1;
            hi += 1;
        }

        return static_cast<int>(hi - lo - 1);
    }

public:
    static int countSubstrings(const string& s) {
        const isize len = std::ssize(s);
        int cnt = 0;

        for (isize i = 0; i < len; i += 1) {
            const int len_odd = calc_len_palindrome(s, len, i, i);
            const int len_even = calc_len_palindrome(s, len, i - 1, i);

            cnt += ((len_odd + 1) / 2) + (len_even / 2);
        }

        return cnt;
    }
};
