class Solution {
    static inline bool is_vowel(const char ch) {
        return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
               ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' ||ch == 'U';
    }

public:
    static string reverseVowels(string s) {
        ptrdiff_t len = std::ssize(s);
        ptrdiff_t lo = 0;
        ptrdiff_t hi = len - 1;

        while (lo < hi) {
            while (lo < hi && !is_vowel(s[hi])) {
                hi -= 1;
            }

            while (lo < hi && !is_vowel(s[lo])) {
                lo += 1;
            }

            const char temp = s[lo];
            s[lo] = s[hi];
            s[hi] = temp;

            hi -= 1;
            lo += 1;
        }

        return s;
    }
};
