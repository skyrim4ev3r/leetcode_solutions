class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t s_len{s.size()};
        size_t t_len{t.size()};

        size_t s_index{0};
        size_t t_index{0};

        while (true) {
            if (s_index == s_len) {
                return true;
            }

            if (t_index == t_len) {
                return false;
            }

            if (s[s_index] == t[t_index]) {
                s_index += 1;
            }

            t_index += 1;
        }
    }
};
