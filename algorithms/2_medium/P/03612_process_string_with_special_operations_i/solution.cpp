class Solution {
public:
    static string processStr(const string& s) {
        auto res = string();

        for (const auto ch: s) {
            if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            } else if (ch == '#') {
                res.insert(res.end(), res.begin(), res.end());
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
