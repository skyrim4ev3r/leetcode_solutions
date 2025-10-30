class Solution {
public:
    string processStr(string s) {
        string res{};

        for (const char &ch: s) {
            if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            } else if (ch == '#') {
                res += res;
            } else if (ch == '%') {
                reverse(res.begin(), res.end());
            } else {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
        }

        return res;
    }
};
