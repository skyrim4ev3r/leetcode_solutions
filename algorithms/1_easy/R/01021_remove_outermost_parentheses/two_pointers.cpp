class Solution {
public:
    string removeOuterParentheses(string s) {
        string res{};
        size_t left_index{0};
        int open_count{0};
        int close_count{0};
        const size_t s_len{s.size()};

        for (size_t i{0}; i < s_len; ++i) {
            if (s[i] == '(') {
                open_count += 1;
            } else {
                close_count += 1;
            }

            if (open_count == close_count) {
                size_t width{i - left_index - 1};
                res += s.substr(left_index + 1, width);
                left_index = i + 1;
                open_count = 0;
                close_count = 0;
            }
        }

        return res;
    }
};
