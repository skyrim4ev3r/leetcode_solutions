class Solution {
    static void check_palindrom(
        const string &s,
        const size_t len,
        size_t left,
        size_t right,
        size_t &max_width,
        size_t &max_width_start_idx
    ) {
        while (left > 0 && right < len - 1 && s[left - 1] == s[right + 1]) {
            left -= 1;
            right += 1;
        }

        const size_t width = right - left + 1;

        if (width > max_width) {
            max_width = width;
            max_width_start_idx = left;
        }
    }
public:
    static string longestPalindrome(const string& s) {
        const size_t len = s.size();
        size_t max_width = 0;
        size_t max_width_start_idx = 0;

        for (size_t i = 0; i < len; ++i) {
            if (i > 0 && s[i - 1] == s[i]) {
                check_palindrom(s, len, i - 1, i, max_width, max_width_start_idx);
            }

            check_palindrom(s, len, i, i, max_width, max_width_start_idx);
        }

        return s.substr(max_width_start_idx, max_width);
    }
};
