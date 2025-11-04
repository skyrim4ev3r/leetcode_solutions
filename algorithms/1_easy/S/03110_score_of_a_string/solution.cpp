class Solution {
public:
    int scoreOfString(string s) {
        int res{0};
        const size_t len{s.size()};

        for (size_t i{0}; i < len - 1; ++i) {
            res += abs((int)s[i + 1] - (int)s[i]);
        }

        return res;
    }
};
