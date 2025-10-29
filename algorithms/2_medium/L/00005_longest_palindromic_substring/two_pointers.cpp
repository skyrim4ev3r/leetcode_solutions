class Solution {
    inline void __attribute__((always_inline)) helper(string &s, size_t &len, size_t &left, size_t &right, size_t &max_start_idx, size_t &max_width) {
        while (left > 0 && right < len - 1 && s[left - 1] == s[right + 1]) {
            left -= 1;
            right += 1;
        }

        size_t width{right - left + 1};

        if (width > max_width) {
            max_width = width;
            max_start_idx = left;
        }
    }
public:
    string longestPalindrome(string s) {

        size_t max_width{0};
        size_t max_start_idx{0};
        size_t len{s.size()};
        size_t left{0};
        size_t right{0};

        for (size_t i{0}; i < len; ++i) {
            if (i > 0 && s[i - 1] == s[i]) {
                left = i - 1;
                right = i;
                helper(s, len, left, right, max_start_idx, max_width);
            }

            left = i;
            right = i;
            helper(s, len, left, right, max_start_idx, max_width);
        }

        return s.substr(max_start_idx, max_width);
    }
};
