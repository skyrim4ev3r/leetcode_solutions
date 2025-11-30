class Solution {
public:
    string replaceDigits(string s) {
        const size_t len{s.size()};

        for (size_t i{1}; i < len; i += 2) {
            s[i] = s[i] - '0' + s[i - 1];
        }

        return s;
    }
};
