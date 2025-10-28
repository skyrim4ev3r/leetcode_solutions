/*
    using flags for different cases, the name of flags are clear and does not need any more explanation
*/

class Solution {
public:
    bool isNumber(string s) {

        bool contains_e{false}, contains_dot{false}, contains_digits_before_e{false}, contains_digits_after_e{false};
        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {

            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                if (s[i] != 'e' && s[i] != 'E') {
                    return false;
                }
            }

            if (s[i] == '-' || s[i] == '+') {
                if (contains_e) {
                    if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                        return false;
                    }
                } else {
                    if (i != 0) {
                        return false;
                    }
                }
            }

            if (s[i] == 'e' || s[i] == 'E') {
                if (contains_e || !contains_digits_before_e) {
                    return false;
                }
                contains_e = true;
            }

            if (s[i] == '.') {
                if (contains_e ||  contains_dot) {
                    return false;
                }
                contains_dot = true;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                if (contains_e) {
                    contains_digits_after_e = true;
                } else {
                    contains_digits_before_e = true;
                }
            }
        }

        if (!contains_digits_before_e || (contains_e && !contains_digits_after_e)) {
            return false;
        }

        return true;
    }
};
