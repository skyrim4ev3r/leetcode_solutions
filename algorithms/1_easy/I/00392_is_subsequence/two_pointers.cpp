class Solution {
public:
    static bool isSubsequence(const string& s, const string& t) {
        const ptrdiff_t s_len = std::ssize(s);
        const ptrdiff_t t_len = std::ssize(t);

        ptrdiff_t s_idx = 0;
        ptrdiff_t t_idx = 0;

        while (s_idx < s_len && t_idx < t_len) {
            if (s[s_idx] == t[t_idx]) {
                s_idx += 1;
            }

            t_idx += 1;
        }

        return s_idx == s_len;
    }
};
