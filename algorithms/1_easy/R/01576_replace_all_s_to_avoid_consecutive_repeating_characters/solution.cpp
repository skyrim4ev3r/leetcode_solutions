class Solution {
public:
    string modifyString(string s) {
        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] == '?') {
                bool a_allowed{true};
                bool b_allowed{true};

                if ((i > 0 && s[i - 1] == 'a') || (i + 1 < len && s[i + 1] == 'a')) {
                    a_allowed = false;
                }

                if ((i > 0 && s[i - 1] == 'b') || (i + 1 < len && s[i + 1] == 'b')) {
                    b_allowed = false;
                }

                if (a_allowed) {
                    s[i] = 'a';
                } else if (b_allowed) {
                    s[i] = 'b';
                } else {
                    s[i] = 'c';
                }
            }
        }

        return s;
    }
};
