typedef ptrdiff_t isize;

class Solution {
    static inline bool is_palindrome(span<const char> b) {
        const isize len = std::ssize(b);
        if (len <= 1) { return true; }
        isize lo = 0;
        isize hi = len - 1;

        while (lo < hi) {
            if (b[lo] != b[hi]) {
                return false;
            }

            lo += 1;
            hi -= 1;
        }

        return true;
    }

    static inline bool is_palindrome_by_split(const string& b1, const string& b2) {
        assert(std::ssize(b1) == std::ssize(b2));
        const isize len = std::ssize(b1);
        if (len <= 1) { return true; }

        isize lo = 0;
        isize hi = len - 1;

        while (lo < hi && b1[lo] == b2[hi]) {
            lo += 1;
            hi -= 1;
        }

        auto use_b1 = span<const char>(b1.data() + lo, hi - lo + 1);
        auto use_b2 = span<const char>(b2.data() + lo, hi - lo + 1);

        return is_palindrome(use_b1) || is_palindrome(use_b2);
    }
public:
    static bool checkPalindromeFormation(const string& b1, const string& b2) {
        return is_palindrome_by_split(b1, b2) || is_palindrome_by_split(b2, b1);
    }
};
