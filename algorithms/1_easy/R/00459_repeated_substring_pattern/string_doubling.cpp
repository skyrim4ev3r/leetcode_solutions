class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const size_t len{s.size()};

        if (len < 2) {
            return false;
        }

        string s_doubled = s + s;

        return s_doubled.substr(1, 2 * len - 2).find(s) != string::npos;
    }
};
